#include "ImagePoolProvider.h"

#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

namespace uicommon {

struct ImagePoolHeader {
    uint32_t width;
    uint32_t height;
    uint32_t numberImage;
    uint32_t scanLineLength;
    uint32_t imageFormat;
};

class ImagePoolProviderPrivate
{
public:
    ImagePoolProviderPrivate(const QString& poolFile):mPoolFile(poolFile)
    {
        struct stat  sb;

        mPoolFileFd = open(mPoolFile.toStdString().c_str(),O_RDONLY);
        if (mPoolFileFd < 0) {
            std::string errSt = "Unable to open the image pool data file: ";
            errSt += mPoolFile.toStdString();
            throw std::runtime_error(errSt.c_str());
        }

        if (fstat(mPoolFileFd, &sb) == -1) {
            throw std::runtime_error("Unable to read the image pool data file");
        }

        if (((sb.st_size & ((1<<13) - 1)) != 0) && (sb.st_size <= 8192)) {
            throw std::runtime_error("Image pool data file has invalid length");
        }

        size_t rdLen;

        rdLen = read(mPoolFileFd,&mFileHeader,sizeof(mFileHeader));
        if (rdLen < sizeof(mFileHeader)) {
            (void)close(mPoolFileFd);
            throw std::runtime_error("Unable to read the image pool data file");
        }
// Fix klocwork START
        uint32_t heightTmp =  mFileHeader.height;
        uint32_t scanLineLengthTmp =  mFileHeader.scanLineLength;
        mImageSize = static_cast<size_t>(heightTmp * scanLineLengthTmp);
// Fix klocwork END
        mMapSize = sb.st_size - static_cast<size_t>(8192);

        mMapAddr = (uchar*)mmap(NULL,mMapSize,PROT_READ,MAP_PRIVATE,mPoolFileFd,8192);
        if (mMapAddr == (uchar*)MAP_FAILED) {
            (void)close(mPoolFileFd);
            throw std::runtime_error("Unable to map the image pool data file");
        }
    }

    ~ImagePoolProviderPrivate() {
        (void)munmap(mMapAddr,mMapSize);
        (void)close(mPoolFileFd);
    }

    ImagePoolHeader mFileHeader;

    int mPoolFileFd;
    QString mPoolFile;
    size_t mImageSize;

    size_t mMapSize;

    uchar *mMapAddr;
};

ImagePoolProvider::ImagePoolProvider(const QString& poolFile):QQuickImageProvider(QQmlImageProviderBase::ImageType::Image)
{
    mPriv = new ImagePoolProviderPrivate(poolFile);
}

ImagePoolProvider::~ImagePoolProvider()
{
    delete mPriv;
}

QImage ImagePoolProvider::requestImage(const QString &idx, QSize *size, const QSize &requestedSize)
{
    bool okFlg;
    uint index = idx.toUInt(&okFlg);
    //Fix klocwork START
    QImage img;
    if ((okFlg == false) || (index >= mPriv->mFileHeader.numberImage)) {
        img = QImage();
    }else{
        int width = 0;
        int height = 0;

        uint32_t fWidth = mPriv->mFileHeader.width;
        uint32_t fHeight = mPriv->mFileHeader.height;
        if(fWidth <= INT_MAX){
            width = fWidth;
        }
        if(fHeight <= INT_MAX){
            height = fHeight;
        }

        if (size != nullptr) {
            size->setWidth(width);
            size->setHeight(height);
        }

        if (requestedSize.width() >= 0) {
            width = std::min(width,requestedSize.width());
        }

        if (requestedSize.height() >=0) {
            height = std::min(height,requestedSize.height());
        }

        img = QImage(&mPriv->mMapAddr[index * mPriv->mImageSize],
                     width,
                     height,
                     mPriv->mFileHeader.scanLineLength,
                     static_cast<QImage::Format>(mPriv->mFileHeader.imageFormat));
    }
    return img;
    //Fix klocwork END
}

}

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTimer>
#include <QImage>

struct ImagePoolHeader {
    uint32_t width;
    uint32_t height;
    uint32_t numberImage;
    uint32_t scanLineLength;
    uint32_t imageFormat;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("ImagePoolCreator helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("dir","The folder contains PNG files");
    parser.addPositionalArgument("outfile","The output image pool file");
    parser.addOptions({
                       {{"p","prefix"},"Prefix of file name","prefix"},
                       {{"w","windex"},"The width of index number. Default: 5","windex","5"},
                       {{"f","from"},"The start index number","start"},
                       {{"t","to"},"The end index number","end"}
    });

    parser.process(a);

    QTimer timer;
    timer.setInterval(0);
    timer.setSingleShot(true);

    QObject::connect(&timer,&QTimer::timeout,[&parser, &a]() {
        qInfo() << "Start processing";

        QString prefix = parser.value("prefix");
        QString windex = parser.value("windex");
        QString from = parser.value("from");
        QString to = parser.value("to");
        QString dir;
        QString outFile;

        do {
            if (parser.positionalArguments().length() < 2) {
                qCritical() << "Must specify the folder containing PNG files and output file";
                parser.showHelp();
                break;
            }

            dir = parser.positionalArguments()[0];
            outFile = parser.positionalArguments()[1];

            if (from.length() == 0) {
                qCritical() << "Must specify start index number";
                parser.showHelp();
                break;
            }

            if (to.length() == 0) {
                qCritical() << "Must specify end index number";
                parser.showHelp();
                break;
            }

            uint _from,_to, _windex;
            bool _parseNumFlg;

            _from = from.toUInt(&_parseNumFlg);
            if (!_parseNumFlg) {
                qCritical() << "Must specify valid start index number";
                parser.showHelp();
                break;
            }

            _to = to.toUInt(&_parseNumFlg);
            if (!_parseNumFlg) {
                qCritical() << "Must specify valid end index number";
                parser.showHelp();
                break;
            }

            if (_from > _to) {
                qCritical() << "Start index number must be less than end index number";
                parser.showHelp();
                break;
            }

            _windex = windex.toUInt(&_parseNumFlg);
            if (!_parseNumFlg) {
                qCritical() << "Must specify valid width of index number";
                parser.showHelp();
                break;
            }

            int i=0;
            FILE* fd = nullptr;
            size_t imageSize = 0;

            uint8_t tmpBuf[8192];

            memset(tmpBuf,0,sizeof(tmpBuf));

            for (int j=_from;j<=_to;++j,++i) {
                int wrLen;
                QString fileName = dir+"/"+prefix+QString::asprintf("%0*u",_windex,j) + ".png";
                QImage image(fileName);

                if (image.isNull()) {
                    qCritical() << "Unable to read the image: " + fileName;
                    break;
                }

                if (i==0) {
                    ImagePoolHeader header;

                    header.width = image.width();
                    header.height = image.height();
                    header.numberImage = (_to - _from + 1);
                    header.scanLineLength = image.bytesPerLine();
                    header.imageFormat = image.format();



                    qInfo() << "Image width: " << header.width;
                    qInfo() << "Image height: " << header.height;
                    qInfo() << "Number of image: " << header.numberImage;

                    fd = fopen(outFile.toStdString().c_str(),"w+");



                    if (fd == nullptr) {
                        qCritical() << "Unable to create file: " << outFile;
                        break;
                    }

                    wrLen = fwrite(&header,sizeof(header),1,fd);
                    if (wrLen < 1)  {
                        qCritical() << "Unable to write to file: " << outFile;
                        break;
                    }

                    wrLen = fwrite(tmpBuf,sizeof(tmpBuf) - sizeof(header),1,fd);
                    if (wrLen < 1)  {
                        qCritical() << "Unable to write to file: " << outFile;
                        break;
                    }

                    imageSize = image.height()*image.bytesPerLine();
                }

                qInfo() << "Processing image: " << fileName;
                wrLen = fwrite(image.bits(),imageSize,1,fd);
                if (wrLen < 1) {
                    qCritical() << "Unable to write to file: " << outFile;
                    break;
                }
            }

            imageSize = imageSize * i;
            size_t alignSize = ((imageSize + ((1<<13) - 1)) & (~((1<<13) - 1))) - imageSize;

            if (alignSize > 0) {
                if (fwrite(tmpBuf,alignSize,1,fd) < 1) {
                    qCritical() << "Unable to write to file: " << outFile;
                }
            }

            if (fd != nullptr) {
                fclose(fd);
            }

            qInfo() << "Finish";
        }
        while(0);

        a.quit();
    });

    timer.start();

    return a.exec();
}

#ifndef IMAGEPOOLPROVIDER_H
#define IMAGEPOOLPROVIDER_H

#include <QQuickImageProvider>
#include <QObject>

namespace uicommon {

class ImagePoolProviderPrivate;
class ImagePoolProvider : public QQuickImageProvider
{
public:
    ImagePoolProvider(const QString& poolFile);
    ~ImagePoolProvider();
    QImage requestImage(const QString &idx, QSize *size, const QSize &requestedSize) override;

    // Start Fix klocwork [CL.FFM.ASSIGN, CL.FFM.COPY]
    ImagePoolProvider& operator=(const ImagePoolProvider& _other) = delete;
    ImagePoolProvider(const ImagePoolProvider& _other) = delete;
    // End Fix klocwork [CL.FFM.ASSIGN, CL.FFM.COPY]
protected:
    ImagePoolProviderPrivate * mPriv;
};

}

#endif // IMAGEPOOLPROVIDER_H

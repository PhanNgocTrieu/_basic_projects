#ifndef UICOMMON_PROXY_MEDIA_DEF_H
#define UICOMMON_PROXY_MEDIA_DEF_H

namespace uicommon
{
    //Brief: intent of action when call request service
    enum MediaActionIntent 
    {
        MediaActionIntentBackground, //action comes from service
        MediaActionIntentUser,       //action comes from user
        MediaActionIntentForce,      //action comes from service but need force to process.
    };

    //NOTE: This enum must be match with MediaEnum::MediaAdapterType
    enum MediaAdapterType
    {
        MediaAdapterAM          = 0,
        MediaAdapterFM,
        MediaAdapterDAB,
        MediaAdapterDRM,
        MediaAdapterRDS,
        MediaAdapterUSB, //5
        MediaAdapterIPOD,
        MediaAdapterBTAudio,
        MediaAdapterAVOFF,
        MediaAdapterHDMI,
        MediaAdapterTV, //10
        MediaAdapterTrafficInfo,
        MediaAdapterAlexa,
        MediaAdapterAppleCarplay,
        MediaAdapterAndroidAuto,
        MediaAdapterPhone,
        MediaAdapterNum //16
    };
}

#endif //UICOMMON_PROXY_MEDIA_DEF_H
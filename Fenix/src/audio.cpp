
#include <Audioclient.h>
#include <Mmdeviceapi.h>



struct AudioState;
extern AudioState *AS;


struct Audio
{
    char* file;
    char* name;

    int channels;
    int samplerate;
    int bitsPerSample;

};



struct AudioState
{
    IMMDevice *audioDevice;
    IMMDeviceEnumerator *deviceEnumenator;
    IAudioClient *audioClient;
    IAudioRenderClient *renderClient;
};


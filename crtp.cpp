#include <vector>

using Samples=std::vector<std::byte>;
using Stream=std::vector<std::byte>;

template<typename Derived>
class Decoder
{
public:
    Samples GetChannel(int channel_number)
    {
        Samples channel;
        Derived* derived = static_cast<Derived*>(this);
        FillSampleFromChannelN(
            channel,
            derived->GetChannelNumber(),
            derived->GetSampleSize(),
            derived->GetSamplesNumber()
        );
        return channel;
    };

private:
    void FillSampleFromChannelN(Samples& channel, int channel_number, int sample_size, int samples_number){
        // Copy to single channel samples container from multi channel container
        // Take into account interleaving, sample size and channel number  
    };
};

class Mp3Decoder : public Decoder<Mp3Decoder>
{
public:
    void Decode(Stream stream){
        // Magic: decode stream to samples
    };
    int GetChannelNumber(){return channel_number;};
    int GetSampleSize(){return sample_size;};
    int GetSamplesNumber(){return samples_number;};
    const Samples& GetSamples(){return samples;};

private:
    Samples samples;
    int channel_number, sample_size, samples_number;
};


int main()
{
    Decoder<Mp3Decoder> mp3_dec = Mp3Decoder(); // Slicing
    Samples channel0 = mp3_dec.GetChannel(0);
    return 0;
}

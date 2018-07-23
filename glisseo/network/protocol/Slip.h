#ifndef NETWORKING_PROTOCOL_SLIP_H_
#define NETWORKING_PROTOCOL_SLIP_H_

#include <string>
#include <vector>

namespace Glisseo {

typedef std::string SlipFrame;
typedef std::vector<SlipFrame> SlipFrames;

/// Implementation of the SLIP (serial line IP) protocol framing with delimiters on both ends
class Slip {
public:
    Slip(void);
    virtual ~Slip() = default;

    /// Append data to the internal buffer
    void appendReceivedData(const std::string& receivedData);
    /// Reset the internal buffer
    void resetReceiveBuffer(void);
    /// Get the content of the internal buffer
    const std::string getReceiveBuffer(void) const;
    /// Get the position of the first set of frame delimiters within the internal buffer, used for unit test
    void getFrameDelimiters(std::string::size_type& first, std::string::size_type& second) const;

    /// True if the internal buffer has at least one frame
    bool hasFrame(void) const;
    /// Extract the first frame from the internal buffer
    void getFrame(SlipFrame& frame);
    /// Extract all frames from the internal buffer
    void getFrames(SlipFrames& frames);

    /// Encode a message according to the SLIP protocol
    static std::string encodeFrame(const SlipFrame& frame);

    /// Replace characters according to the SLIP protocol
    static std::string escapeFrame(const SlipFrame& input);
    /// Replace characters according to the SLIP protocol
    static std::string unescapeFrame(const SlipFrame& input);

private:
    std::string receiveBuffer;
};

} /* namespace Glisseo */

#endif /* NETWORKING_PROTOCOL_SLIP_H_ */

#ifndef GLISSEO_NETWORK_PROTOCOL_MESSAGES_H_
#define GLISSEO_NETWORK_PROTOCOL_MESSAGES_H_

#include <string>
#include <vector>
#include <json/json.h>

namespace Glisseo {

typedef std::vector<std::string> Messages;
typedef std::vector<Json::Value> JsonMessages;

} /* namespace Glisseo */

#endif /* GLISSEO_NETWORK_PROTOCOL_MESSAGES_H_ */

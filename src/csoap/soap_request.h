#ifndef CSOAP_SOAP_REQUEST_H_
#define CSOAP_SOAP_REQUEST_H_

#include <vector>

#include "csoap/soap_message.h"

namespace csoap {

// SOAP request.
// Used to compose the SOAP request envelope XML which will be sent as the HTTP
// request body.
class SoapRequest : public SoapMessage {
public:
  CLIENT_API void AddParameter(const std::string& key, const std::string& value);
  CLIENT_API void AddParameter(const Parameter& parameter);

  // Get parameter value by key.
  SERVER_API std::string GetParameter(const std::string& key) const;

protected:
  void ToXmlBody(pugi::xml_node xbody) override;
  bool FromXmlBody(pugi::xml_node xbody) override;

private:
  std::vector<Parameter> parameters_;
};

}  // namespace csoap

#endif  // CSOAP_SOAP_REQUEST_H_
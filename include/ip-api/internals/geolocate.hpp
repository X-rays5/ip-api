//
// Created by X-ray on 3/5/2022.
//

#pragma once

#ifndef IP_API_GEOLOCATE_HPP
#define IP_API_GEOLOCATE_HPP
#include "winhttp/winhttp_client.hpp"
#include "shared.hpp"

namespace ip_api {
  namespace geolocate {
    enum class Format {
      kJson,
      kXml,
      kCsv,
      kNewline,
    };

    std::string FormatToString(Format format) {
      switch(format) {
        case Format::kJson:
          return "json";
        case Format::kXml:
          return "xml";
        case Format::kCsv:
          return "csv";
        case Format::kNewline:
          return "line";
      }
      return {};
    }

    std::string Request(const std::string& ip, Format format, Options options = Options::kNone) {
      winhttp::Req req(winhttp::Method::kGet, "http://ip-api.com/" + FormatToString(format) + "/" + ip + "?fields=" + OptionsToString(options));
      auto res = winhttp::client::Request(req);

      if(res.status_code != 200) {
        throw std::runtime_error("Request failed with status code " + std::to_string(res.status_code));
      } else {
        return res.body;
      }
    }
  }
}
#endif //IP_API_GEOLOCATE_HPP

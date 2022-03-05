//
// Created by X-ray on 3/5/2022.
//

#pragma once

#ifndef IP_API_BATCH_HPP
#define IP_API_BATCH_HPP
#include <array>
#include <sstream>
#include "shared.hpp"
#include "winhttp/winhttp_client.hpp"

namespace ip_api {
  namespace geolocate {
    namespace batch {
      inline std::string GetQuery(const std::array<std::string, 100>& ip_arr) {
        std::stringstream ss;
        ss << '[';
        for (auto&& ip : ip_arr) {
          if (ip.empty()) {
            continue;
          }
          ss << "\"" << ip << "\",";
        }
        auto res = ss.str();
        res.pop_back();
        res.append("]");

        return res;
      }

      std::string Request(const std::array<std::string, 100>& ip_arr, Options options = Options::kNone) {
        if (ip_arr.empty())
          throw std::runtime_error("ip_arr is empty");

        winhttp::Req request(winhttp::Method::kPost, std::string("http://ip-api.com/batch") + "?fields=" + OptionsToString(options));
        request.body = GetQuery(ip_arr);
        request.headers["Content-Type"] = "application/json";

        auto res = winhttp::client::Request(request);
        if (res.status_code != 200) {
          throw std::runtime_error("Request failed with status code " + std::to_string(res.status_code));
        } else {
          return res.body;
        }
      }
    }
  }
}
#endif //IP_API_BATCH_HPP

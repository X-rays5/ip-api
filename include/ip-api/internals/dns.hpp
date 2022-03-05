//
// Created by X-ray on 3/5/2022.
//

#pragma once

#ifndef IP_API_DNS_HPP
#define IP_API_DNS_HPP
#include "winhttp/winhttp_client.hpp"

namespace ip_api {
  namespace dns {
    // generate random string
    std::string RandomString(size_t length) {
      auto randchar = []() -> char {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
      };
      std::string str(length, 0);
      std::generate_n(str.begin(), length, randchar);
      return str;
    }

    std::string Request() {
      winhttp::Req req(winhttp::Method::kGet, "http://" + RandomString(32) + ".edns.ip-api.com/json");
      auto res = winhttp::client::Request(req);
      if (res.status_code != 200) {
        throw std::runtime_error("Request failed");
      } else {
        return res.body;
      }
    }
  }
}
#endif //IP_API_DNS_HPP

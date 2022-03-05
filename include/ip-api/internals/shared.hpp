//
// Created by X-ray on 3/5/2022.
//

#pragma once

#ifndef IP_API_SHARED_HPP
#define IP_API_SHARED_HPP
#include <string>

namespace ip_api {
  enum class Options {
    kContinent = 0x00, /// < Continent name
    kContinentCode = 0x01, /// < Continent code, 3-letter ISO 3166-1 code.
    kCountry = 0x02, /// < Country name
    kCountryCode = 0x04, /// < Country code, ISO 3166-1 alpha-2
    kRegion = 0x08, /// < Region/state short code (FIPS or ISO)
    kRegionName = 0x16, /// < Region/state
    kCity = 0x32, /// < City
    kDistrict = 0x64, /// < District (subdivision of city)
    kZip = 0x128, /// < Zip code
    kLatitude = 0x256, /// < Latitude
    kLongitude = 0x512, /// < Longitude
    kTimezone = 0x1024, /// < Timezone
    kOffset = 0x2048, /// < Timezone UTC DST offset in seconds
    kCurrency = 0x4096, /// National currency
    kIsp = 0x8192, /// < ISP
    kOrg = 0x16384, /// < Organization
    kAs = 0x32768, /// <	AS number and organization, separated by space (RIR). Empty for IP blocks not being announced in BGP tables.
    kAsname = 0x65536, /// <	AS name (RIR). Empty for IP blocks not being announced in BGP tables.
    kReverse = 0x131072, /// < Reverse DNS of the IP (can delay response)
    kMobile = 0x262144, /// < Mobile (cellular) connection
    kProxy = 0x524288, /// < Proxy, VPN or Tor exit address
    kHosting = 0x1048576, /// 	Hosting, colocated or data center
    kQuery = 0x2097152, /// IP used for the query
    kNone = 0x68346532, /// < No option
  };
  inline Options operator|(Options lhs, Options rhs) {
    return static_cast<Options>(static_cast<int>(lhs) | static_cast<int>(rhs));
  }
  inline Options operator&(Options lhs, Options rhs) {
    return static_cast<Options>(static_cast<int>(lhs) & static_cast<int>(rhs));
  }

  // data to options string
  std::string OptionsToString(Options options) {
    std::string res;
    if ((Options::kContinent & options) == Options::kContinent) {
      res += "continent,";
    }
    if ((Options::kContinentCode & options) == Options::kContinentCode) {
      res += "continent_code,";
    }
    if ((Options::kCountry & options) == Options::kCountry) {
      res += "country,";
    }
    if ((Options::kCountryCode & options) == Options::kCountryCode) {
      res += "country_code,";
    }
    if ((Options::kRegion & options) == Options::kRegion) {
      res += "region,";
    }
    if ((Options::kRegionName & options) == Options::kRegionName) {
      res += "region_name,";
    }
    if ((Options::kCity & options) == Options::kCity) {
      res += "city,";
    }
    if ((Options::kDistrict & options) == Options::kDistrict) {
      res += "district,";
    }
    if ((Options::kZip & options) == Options::kZip) {
      res += "zip,";
    }
    if ((Options::kLatitude & options) == Options::kLatitude) {
      res += "latitude,";
    }
    if ((Options::kLongitude & options) == Options::kLongitude) {
      res += "longitude,";
    }
    if ((Options::kTimezone & options) == Options::kTimezone) {
      res += "timezone,";
    }
    if ((Options::kOffset & options) == Options::kOffset) {
      res += "offset,";
    }
    if ((Options::kCurrency & options) == Options::kCurrency) {
      res += "currency,";
    }
    if ((Options::kIsp & options) == Options::kIsp) {
      res += "isp,";
    }
    if ((Options::kOrg & options) == Options::kOrg) {
      res += "org,";
    }
    if ((Options::kAs & options) == Options::kAs) {
      res += "as,";
    }
    if ((Options::kAsname & options) == Options::kAsname) {
      res += "asname,";
    }
    if ((Options::kReverse & options) == Options::kReverse) {
      res += "reverse,";
    }
    if ((Options::kMobile & options) == Options::kMobile) {
      res += "mobile,";
    }
    if ((Options::kProxy & options) == Options::kProxy) {
      res += "proxy,";
    }
    if ((Options::kHosting & options) == Options::kHosting) {
      res += "hosting,";
    }
    if ((Options::kQuery & options) == Options::kQuery) {
      res += "query,";
    }
    if (!res.empty()) {
      res.pop_back();
    }
    return res;
  }

  inline Options AllOptions() {
    return Options::kContinent |
           Options::kContinentCode |
           Options::kCountry |
           Options::kCountryCode |
           Options::kRegion |
           Options::kRegionName |
           Options::kCity |
           Options::kDistrict |
           Options::kZip |
           Options::kLatitude |
           Options::kLongitude |
           Options::kTimezone |
           Options::kOffset |
           Options::kCurrency |
           Options::kIsp |
           Options::kOrg |
           Options::kAs |
           Options::kAsname |
           Options::kReverse |
           Options::kMobile |
           Options::kProxy |
           Options::kHosting |
           Options::kQuery;
  }
}
#endif //IP_API_SHARED_HPP

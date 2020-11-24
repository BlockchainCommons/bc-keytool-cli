#ifndef KEYTOOL_ASSET_HPP
#define KEYTOOL_ASSET_HPP

#include <string>
#include <vector>
#include <ostream>
#include "network.hpp"

class Asset final {
public:
    Asset(const std::string& name, const std::string& symbol, Network const &network, size_t coin_type, uint8_t version_pkh, uint8_t version_sh)
        : _name(name)
        , _symbol(symbol)
        , _network(network)
        , _coin_type(coin_type)
        , _version_pkh(version_pkh)
        , _version_sh(version_sh)
        { }

    const std::string& name() const { return _name; }
    const std::string& symbol() const { return _symbol; }
    Network network() const { return _network; }
    size_t coin_type() const { return _coin_type; }
    uint8_t version_pkh() const { return _version_pkh; }
    uint8_t version_sh() const { return _version_sh; }

    static Asset btc();
    static Asset btct();
    static std::vector<Asset> assets();

    static Asset find(const std::string& symbol);

private:
    std::string _name;
    std::string _symbol;
    Network _network;
    size_t _coin_type;
    uint8_t _version_pkh;
    uint8_t _version_sh;
};

std::ostream& operator<< (std::ostream& os, const Asset& asset);

#endif // KEYTOOL_ASSET_HPP

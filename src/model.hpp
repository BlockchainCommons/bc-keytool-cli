#ifndef KEYTOOL_MODEL_HPP
#define KEYTOOL_MODEL_HPP

#include "data-node.hpp"
#include "asset.hpp"
#include "hd-key.hpp"
#include "ec-key.hpp"
#include "utils.hpp"
#include "wally-utils.hpp"
#include "derivation-path.hpp"
#include "chain-type.hpp"
#include "output-type.hpp"
#include "index-bound.hpp"
#include "output-descriptor.hpp"
#include "psbt.hpp"
#include "transaction.hpp"
#include "seed.hpp"
#include "uuid.hpp"
#include "request.hpp"

class Model final {
public:
    Model();

    DataNodeProtocol* find_by_name(const std::string& node_name) const;
    DataNodeProtocol* find_by_tag(int node_tag) const;
    bool is_valid_name(const std::string& node_name) const;
    bool can_derive(const std::string& node_name) const;
    const std::vector<DataNodeProtocol*>& all_nodes() const {
        return _all_nodes;
    }
    const std::vector<std::string>& derivations() const {
        return _derivations;
    }

    void add_node(DataNodeProtocol*);
    void add_derivation(const std::string& d);

    // seed
    DataNode<ByteVector> *seed;
    DataNode<std::string> *seed_name;
    DataNode<std::string> *seed_note;
    DataNode<Seed> *seed_ur;
    DataNode<ByteVector> *seed_digest;
    DataNode<UUID> *request_id;
    DataNode<std::string> *request_description;
    DataNode<Request> *seed_request;

    // ec-key
    DataNode<Asset> *asset;
    DataNode<Network> *network;
    DataNode<ECPrivateKey> *address_ec_key;
    DataNode<std::string> *address_ec_key_wif;
    DataNode<ECCompressedPublicKey> *address_pub_ec_key;
    DataNode<std::string> *address_pkh;
    DataNode<std::string> *address_sh;
    DataNode<std::string> *address_segwit;

    // hd-key
    DataNode<HDKey> *master_key;
    DataNode<ByteVector> *master_key_fingerprint;
    DataNode<OutputDescriptorType> *output_type;
    DataNode<uint32_t> *purpose;
    DataNode<uint32_t> *coin_type;
    DataNode<uint32_t> *account_index;
    DataNode<DerivationPath> *account_derivation_path;
    DataNode<HDKey> *account_key;
    DataNode<HDKey> *account_pub_key;
    DataNode<ChainType> *chain_type;
    DataNode<uint32_t> *chain_type_int;
    DataNode<IndexBound> *address_index;
    DataNode<DerivationPath> *address_derivation_path;
    DataNode<DerivationPath> *full_address_derivation_path;
    DataNode<HDKey> *address_key;
    DataNode<HDKey> *address_pub_key;
    DataNode<OutputDescriptor> *output_descriptor;

    // psbt
    DataNode<PSBT> *psbt;
    DataNode<std::string> *psbt_hex;
    DataNode<std::string> *psbt_ur;
    DataNode<PSBT> *psbt_finalized;
    DataNode<std::string> *psbt_finalized_hex;
    DataNode<std::string> *psbt_finalized_ur;
    DataNode<PSBT> *psbt_signed;
    DataNode<std::string> *psbt_signed_hex;
    DataNode<std::string> *psbt_signed_ur;
    DataNode<Transaction> *transaction;
    DataNode<std::string> *transaction_ur;

private:
    std::vector<DataNodeProtocol*> _all_nodes;
    std::vector<std::string> _derivations;
};

#endif // KEYTOOL_MODEL_HPP

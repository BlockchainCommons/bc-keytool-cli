#ifndef KEYTOOL_PSBT_HPP
#define KEYTOOL_PSBT_HPP

#include "utils.hpp"
#include "ec-key.hpp"
#include <memory>

struct wally_psbt;

class PSBT final {
public:
    PSBT();
    explicit PSBT(const std::string& s); // base64, hex, or ur:crypto-psbt
    explicit PSBT(const ByteVector& data);
    explicit PSBT(wally_psbt* psbt);
    static PSBT from_cbor(const ByteVector& cbor);
    static PSBT decode_cbor(ByteVector::const_iterator& pos, ByteVector::const_iterator end);
    static PSBT decode_tagged_cbor(ByteVector::const_iterator& pos, ByteVector::const_iterator end);

    bool is_finalized() const;
    PSBT finalized() const;

    PSBT sign(const ECPrivateKey& key) const;

    std::string base64() const;
    std::string hex() const;
    std::string ur() const;
    ByteVector data() const;
    ByteVector cbor() const;
    ByteVector tagged_cbor() const;

    // friend class Wally;
    friend class Transaction;

private:
    std::shared_ptr<wally_psbt> _psbt;
};

#endif // KEYTOOL_PSBT_HPP

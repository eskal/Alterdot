// Copyright (c) 2020-2021 Alterdot Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADOT_BDNSDB_H
#define ADOT_BDNSDB_H

#include "dbwrapper.h"

#include <string>
#include <utility>

struct BDNSRecord {
    std::string ipfsHash;
    int regBlockHeight, regTxIndex;
    
    template<typename Stream>
    void Serialize(Stream &s) const {
        s << ipfsHash;
        s << regBlockHeight;
        s << regTxIndex;
    }

    template<typename Stream>
    void Unserialize(Stream& s) {
        s >> ipfsHash;
        s >> regBlockHeight;
        s >> regTxIndex;
    }
};

/** Access to the BDNS database (bdns/) */
class CBDNSDB : public CDBWrapper
{
public:
    CBDNSDB(size_t nCacheSize, bool fMemory = false, bool fWipe = false);

    bool GetIPFSFromBDNSRecord(const std::string &bdnsName, std::string &ipfsHash);
    bool ReadBDNSRecord(const std::string &bdnsName, BDNSRecord &bdnsRecord);
    bool WriteBDNSRecord(const std::string &bdnsName, const BDNSRecord &bdnsRecord);
    bool UpdateBDNSRecord(const std::string &bdnsName, const std::string &ipfsHash);
    bool EraseBDNSRecord(const std::string &bdnsName);
};

#endif // ADOT_BDNSDB_H

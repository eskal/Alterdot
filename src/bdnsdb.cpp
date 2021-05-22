// Copyright (c) 2020-2021 Bitcreds Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "bdnsdb.h"

#include "util.h"

CBDNSDB::CBDNSDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(GetDataDir() / "bdns", nCacheSize, fMemory, fWipe) {}

bool CBDNSDB::GetIPFSFromBDNSRecord(const std::string &bdnsName, std::string &ipfsHash) {
    BDNSRecord storedValue;

    if (Read(bdnsName, storedValue)) {
        ipfsHash = storedValue.ipfsHash;

        return true;
    }

    return false;
}

bool CBDNSDB::ReadBDNSRecord(const std::string &bdnsName, BDNSRecord& bdnsRecord) {
    BDNSRecord storedValue;

    if (Read(bdnsName, storedValue)) {
        bdnsRecord = storedValue;

        return true;
    }

    return false;
}

bool CBDNSDB::WriteBDNSRecord(const std::string &bdnsName, const BDNSRecord &bdnsRecord) {
    CDBBatch batch(*this);
    batch.Write(bdnsName, bdnsRecord);
    return WriteBatch(batch);
}

bool CBDNSDB::UpdateBDNSRecord(const std::string &bdnsName, const std::string &newIpfsHash) {
    BDNSRecord storedValue;

    if (Read(bdnsName, storedValue)) {
        CDBBatch batch(*this);
        storedValue.ipfsHash = newIpfsHash;
        batch.Write(bdnsName, storedValue);
        return WriteBatch(batch);
    }

    return false;
}

bool CBDNSDB::EraseBDNSRecord(const std::string &bdnsName) {
    CDBBatch batch(*this);
    batch.Erase(bdnsName);
    return WriteBatch(batch);
}

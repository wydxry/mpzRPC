#pragma once
#include <iostream>
#include <string>

class MpzrpcConfig
{
private:
    std::string m_rpcserverip;
    int m_rpcserverport;
    std::string m_zookeeperip;
    int m_zookeeperport;
    int m_muduoThreadNum;

public:
    void LoadConfigFromFile(const std::string &config_file);

    std::string &getRpcServerIp()
    {
        return m_rpcserverip;
    }

    int &getRpcServerPort()
    {
        return m_rpcserverport;
    }

    std::string &getZookeeperIp()
    {
        return m_zookeeperip;
    }

    int &getZookeeperPort()
    {
        return m_zookeeperport;
    }

    int &getMuduoThreadNum()
    {
        return m_muduoThreadNum;
    }
};
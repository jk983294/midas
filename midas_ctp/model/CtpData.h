#ifndef MIDAS_CTP_DATA_H
#define MIDAS_CTP_DATA_H

#include <ctp/ThostFtdcUserApiDataType.h>
#include <utils/convert/StringHelper.h>
#include <atomic>
#include <map>
#include <string>
#include <vector>
#include "tbb/concurrent_hash_map.h"

using namespace std;
using namespace midas;

typedef tbb::concurrent_hash_map<string, string, MidasStringHashCompare> ChMapSS;

enum CtpState { TradeInit, MarketInit, Running, Closing };

class CtpData {
public:
    std::atomic<CtpState> state{TradeInit};

    string brokerId;    // 经纪公司代码
    string investorId;  // 投资者代码
    string password;    // 用户密码
    string tradeFront;
    string marketFront;
    string dataDirectory, tradeFlowPath, marketFlowPath;

    // 会话参数
    TThostFtdcFrontIDType frontId;        //前置编号
    TThostFtdcSessionIDType sessionId;    //会话编号
    TThostFtdcOrderRefType orderRef;      //报单引用
    TThostFtdcOrderRefType execOrderRef;  //执行宣告引用
    TThostFtdcOrderRefType forQuoteRef;   //询价引用
    TThostFtdcOrderRefType quoteRef;      //报价引用

    map<string, CThostFtdcInstrumentField> instruments;
    map<string, CThostFtdcExchangeField> exchanges;
    map<string, CThostFtdcProductField> products;
    map<string, CThostFtdcTradingAccountField> accounts;
    vector<CThostFtdcInvestorPositionField> positions;

    ChMapSS user2asyncData;
};

#endif

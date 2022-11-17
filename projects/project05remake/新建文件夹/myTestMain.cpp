#include "ShortestPathForFlight.cpp"

vector<flight> data();

int main() {
    /* 数据输入 */
    vector<flight> test = data();
    /* 由数据建立带权路线图 */
    // 飞行时间 & 总用时
    MGraph<string, int> GFlyingTime = FlyingTimeGraph(test);
    GFlyingTime.printMGraph(1);
    vector<int> path1, path2, path3, path4;
    vector<int> dist1, dist2, dist3, dist4;
    ShortestPath(GFlyingTime, 2, test, dist1, path1);
    ShortestTotalTime(GFlyingTime, 2, test, dist2, path2);
    

    // 花费
    MGraph<string, int> GCosts = CostsGraph(test);
    ShortestPath(GCosts, 2, test, dist3, path3);
    GCosts.printMGraph(1);

    // 中转次数
    MGraph<string, int> GTrans = TransGraph(test);
    ShortestPath(GTrans, 2, test, dist4, path4);
    GTrans.printMGraph(1);
/*
    printFlightsPath(GFlyingTime, dist1, path1, "乌鲁木齐", "上海");
    printFlightsPath(GFlyingTime, dist2, path2, "乌鲁木齐", "上海");
    printFlightsPath(GFlyingTime, dist3, path3, "乌鲁木齐", "上海");
    printFlightsPath(GFlyingTime, dist4, path4, "乌鲁木齐", "上海");*/
}


// 数据输入
vector<flight> data() {
    int i;
    vector<flight> test;
    string num[16] = {
        "6320", "6320",
        "2104", "2104",
        "201", "201",
        "2323", "2323",
        "173", "173",
        "3304", "3304",
        "82", "82",
        "4723", "4723"
    };

    string vertices[16][2] = {
        {"北京", "上海"}, {"上海", "北京"}, 
        {"北京", "乌鲁木齐"}, { "乌鲁木齐", "北京"},
        {"北京", "西安"}, {"西安", "北京"}, 
        {"西安", "广州"}, {"广州", "西安"},
        {"拉萨", "昆明"}, {"昆明", "拉萨"}, 
        {"拉萨", "武汉"}, {"武汉", "拉萨"},
        {"乌鲁木齐", "昆明"}, {"昆明", "乌鲁木齐"}, 
        {"武汉", "广州"}, {"广州", "武汉"}
    };

    time24 times[16][2] = {
        {time24(16,20),time24(17,25)},{time24(18,00),time24(19,05)},
        {time24(8,0),time24(9,55)},{time24(10,45),time24(11,40)},
        {time24(15,25),time24(17,0)},{time24(12,35),time24(14,15)},
        {time24(7,15),time24(9,35)},{time24(10,15),time24(11,35)},
        {time24(10,20),time24(11,45)},{time24(12,35),time24(14,0)},
        {time24(14,15),time24(15,45)},{time24(16,25),time24(17,55)},
        {time24(9,30),time24(12,15)},{time24(13,05),time24(15,50)},
        {time24(7,5),time24(8,45)},{time24(11,25),time24(13,5)}
    };

    int cost[16] = {
        680, 680,
        1150, 1150,
        930, 930,
        1320, 1320,
        830, 830,
        890, 890,
        1480, 1480,
        810, 810
    };

    for (i = 0; i < 16; i++) {
        test.push_back(flight(num[i], vertices[i], times[i], cost[i]));
    }

    return test;
}
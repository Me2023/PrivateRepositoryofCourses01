#include "AQCondition.cpp"

class city {
public:
    int num;                        // 城市序号
    string name;                    // 城市名
    vector<AQCondition> AQCList;    // 该城市对应的所有空气质量状况数据组成的vector

    // 构造函数
    city(int a = 0, string b = "", vector<AQCondition> c = vector<AQCondition>()) 
    : num(a), name(b), AQCList(c) {} 

    // 普通查询：分别查询该城市每天、每周、每月、每季度和全年的空气质量状况
    // 查询该城市每天的空气质量状况
    void searchDayAQ(dateIn2006 d) {
        // 折半查找，注意到AQCList是日期从大到小的有序表
        int n = AQCList.size();
        int left = 0; int right = n-1;
    }
    void searchWeekAQ(int w) {
        // 顺序查找
    }
    void searchMonthAQ(int m) {
        // 顺序查找
    }

};



// 读取txt文件，并将所有数据储存到城市对象组成的vector中
void readAQCs(string txt, vector<city> &cityList) {
    string data;
    string strs[4];
    int nums[5];
    int preNum = 0, curNum = 0; string curName = "";
    city newCity = city();
    // 打开文件
    ifstream infile; 
    infile.open(txt); 
    int i = 0;
    // 开始读取
    while (infile >> data) {
        nums[0] = stoi(data);
        infile >> data;
        for (i = 0; i < 2; i++) {
            strs[i] = data; 
            infile >> data;
        }
        nums[1] = stoi(data);
        for (i = 2; i < 4; i++) {
            infile >> data; 
            strs[i] = data;
        } 
        for (i = 2; i < 5; i++) {
            infile >> data;
            nums[i] = stoi(data); 
        }
        // 读完一行，插入该数据到城市列表
        curNum = nums[0]; curName = strs[0];
        if (curNum != preNum) {
            // 如果和前一行数据的城市不同，插入该新城市，并将该行空气质量数据存入该城市对象中
            newCity = city(curNum, curName);
            newCity.AQCList.push_back(AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]));
            cityList.push_back(newCity);
        }
        else {
            // 如果仍是同一城市，将该行空气质量数据存入该城市对象中
            cityList.back().AQCList.push_back(AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]));
        }
        preNum = curNum;
        cityList.back().AQCList.back().display();
    }
 
    infile.close();
    return;
}


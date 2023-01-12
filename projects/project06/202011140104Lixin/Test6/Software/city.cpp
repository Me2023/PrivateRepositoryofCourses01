#include "AQCondition.cpp"

class city {
public:
    int num;                        // 城市序号
    string name;                    // 城市名
    AQCondition AQCList[12][31];    // 该城市对应的所有空气质量状况数据组成的二维数组

    // 构造函数
    city(int a = 0, string b = "") 
    : num(a), name(b) {} 

    
    /* 普通查询：分别查询该城市每天、每周、每月、每季度和全年的空气质量状况 */
    // 查询该城市每天的空气质量状况
    void searchDayAQ(dateIn2006 d) {
        int mm = d.month, dd = d.day;
        AQCList[mm - 1][dd - 1].display();
    }

    // 查询该城市每周的空气质量状况
    void searchWeekAQ(int w) {
        vector<dateIn2006> dateList;
        daysOfWeek(w, dateList);
        dateIn2006 now;
        int max = dateList.size();
        int i = 0;
        for (i = 0; i < max; i++) {
            now = dateList[i]; // 日期
            // now.display();
            if (AQCList[now.month - 1][now.day - 1].AQCdate.month == 0) {
                cout << name << " 在 "; now.display(); cout << " 没有数据！" << endl;
            }
            else {
                AQCList[now.month - 1][now.day - 1].display();
            }
        }
    }

    // 查询该城市每月的空气质量状况
    void searchMonthAQ(int m) {
        int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int max = mList[m - 1]; // 迭代次数
        for (int i = 1; i <= max; i++) {
            if (AQCList[m - 1][i - 1].AQCdate.month == 0) {
                cout << name << " 在 "; dateIn2006(m, i).display(); cout << " 没有数据！" << endl;
            }
            else {
                AQCList[m - 1][i - 1].display();
            }
        }
    }

    // 查询该城市每季度的空气质量状况
    void searchSeasonAQ(int s) {
        int startMonth = (s - 1) * 3 + 1;
        int endMonth = s * 3;
        for (int i = startMonth; i <= endMonth; i++) {
            searchMonthAQ(i);
        }
    }

    // 查询该城市一整年的空气质量状况
    void searchYearAQ() {
        for (int i = 1; i <= 4; i++) {
            searchSeasonAQ(i);
        }
    }

    /* 统计查询，通过数组返回各空气质量对应的数据 */
    // 统计查询该城市某周的空气质量状况天数，结果通过数组返回
    void staSearchWeekAQ(int w, int num[5] = {0}) {
        vector<dateIn2006> dateList;
        daysOfWeek(w, dateList);
        dateIn2006 now;
        AQCondition p;
        int max = dateList.size();
        int i = 0;
        for (i = 0; i < max; i++) {
            now = dateList[i];
            if (AQCList[now.month - 1][now.day - 1].AQCdate.month != 0) {
                p = AQCList[now.month - 1][now.day - 1];
                if (p.degree == "优") {
                    num[0] += 1;
                }
                else if (p.degree == "良") {
                    num[1] += 1;
                }
                else if (p.degree == "轻微污染") {
                    num[2] += 1;
                }
                else if (p.degree == "轻度污染") {
                    num[3] += 1;
                }
                else if (p.degree == "重污染" || p.degree == "中度重污染") {
                    num[4] += 1;
                }
            }
        }
    }
    // 统计查询该城市某月的空气质量状况，结果通过数组返回
    void staSearchMonthAQ(int m, int num[5] = {0}) {
        int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int max = mList[m - 1]; // 迭代次数
        AQCondition p;
        for (int i = 1; i <= max; i++) {
            if (AQCList[m - 1][i - 1].AQCdate.month != 0) {
                p = AQCList[m - 1][i - 1];
                if (p.degree == "优") {
                    num[0] += 1;
                }
                else if (p.degree == "良") {
                    num[1] += 1;
                }
                else if (p.degree == "轻微污染") {
                    num[2] += 1;
                }
                else if (p.degree == "轻度污染") {
                    num[3] += 1;
                }
                else if (p.degree == "重污染") {
                    num[4] += 1;
                }
            }
        }
    }

    // 统计查询该城市某季度的空气质量状况，结果通过数组返回
    void staSearchSeasonAQ(int s, int num[5] = {0}) {
        int startMonth = (s - 1) * 3 + 1;
        int endMonth = s * 3;
        for (int i = startMonth; i <= endMonth; i++) {
            staSearchMonthAQ(i, num);
        }
    }

    // 统计查询该城市一整年的空气质量状况，结果通过数组返回
    void staSearchYearAQ(int num[5] = {0}) {
        for (int i = 1; i <= 4; i++) {
            staSearchSeasonAQ(i, num);
        }
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
            // 如果和前一行数据的城市不同，插入该新城市，并将该行空气质量数据存入该城市对象的数据数组中
            newCity = city(curNum, curName);
            newCity.AQCList[nums[3] - 1][nums[4] - 1] = AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]);
            cityList.push_back(newCity);
        }
        else {
            // 如果仍是同一城市，将该行空气质量数据存入该城市对象中
            cityList.back().AQCList[nums[3] - 1][nums[4] - 1] = AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]);
        }
        preNum = curNum;
        // cityList.back().AQCList[nums[3] - 1][nums[4] - 1].display();
    }
 
    infile.close();
    return;
}

/* 统计查询 2，根据时间查询空气质量状况 */
// 查询某周某空气质量状况满足大于 min 的城市，城市名通过 result 返回。
void timeSearchWeekAQ(int w, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // 城市个数
    city p;
    int num[5] = {0};
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            num[j] = 0;
        }
        p = cityList[i];
        p.staSearchWeekAQ(w, num);
        if (num[level - 1] > min) {
            result.push_back(p.name);
        } 
    }
}

// 查询某月某空气质量状况满足大于 min 的城市，城市名通过 result 返回。
void timeSearchMonthAQ(int m, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // 城市个数
    city p;
    int num[5] = {0};
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            num[j] = 0;
        }
        p = cityList[i];
        p.staSearchMonthAQ(m, num);
        if (num[level - 1] > min) {
            result.push_back(p.name);
        } 
    }
}

// 查询某季度某空气质量状况满足大于 min 的城市，城市名通过 result 返回。
void timeSearchSeasonAQ(int s, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // 城市个数
    city p;
    int num[5] = {0};
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            num[j] = 0;
        }
        p = cityList[i];
        p.staSearchSeasonAQ(s, num);
        if (num[level - 1] > min) {
            result.push_back(p.name);
        } 
    }
}

// 查询一整年某空气质量状况满足大于 min 的城市，城市名通过 result 返回。
void timeSearchYearAQ(int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // 城市个数
    city p;
    int num[5] = {0};
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        for(int j = 0; j < 5; j++) {
            num[j] = 0;
        }
        p = cityList[i];
        p.staSearchYearAQ(num);
        if (num[level - 1] > min) {
            result.push_back(p.name);
        } 
    }
}


/* 排序查询：输入周编号、月编号、季度编号或年编号，查询城市空气质量的排行榜 */

class cityAQC {
public:
    string name;
    double averageAQ;
    cityAQC(string a = "", double b = 0) : name(a), averageAQ(b) {}

    bool operator<(cityAQC &other) {
        if (averageAQ < other.averageAQ) return true;
        return false;
    }
};

// 通过引用返回某周各城市 城市名-平均空气质量指数 组成的 cityAQC 类的 vector
void weekAverageAQ(int w, vector<city> &cityList, vector<cityAQC> &result) {
    int max = cityList.size(); // 城市个数
    double average = 0; int count = 0;
    vector<dateIn2006> dateList;
    daysOfWeek(w, dateList); dateIn2006 now; AQCondition q;
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // 当前城市
        int mmax = dateList.size();     // 该周天数
        // 读取该周每天的数据
        for (int j = 0; j < mmax; j++) {
            now = dateList[j];
            if (p.AQCList[now.month - 1][now.day - 1].AQCdate.month != 0) {
                q = p.AQCList[now.month - 1][now.day - 1]; // 当前城市当日空气质量数据
                average += (double) q.index;
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// 通过引用返回某月各城市 城市名-平均空气质量指数
void monthAverageAQ(int m, vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // 城市个数
    double average = 0; int count = 0;
    AQCondition q;
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // 当前城市
        int mmax = mList[m - 1];    // 该月天数
        // 读取该月每天的数据
        for (int j = 1; j <= mmax; j++) {
            if (p.AQCList[m - 1][j - 1].AQCdate.month != 0) {
                q = p.AQCList[m - 1][j - 1];    // 当前城市当日空气质量数据
                count += 1;
                average += (double) q.index;
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// 通过引用返回某季度各城市 城市名-平均空气质量指数
void seasonAverageAQ(int s, vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // 城市个数
    double average = 0; int count = 0;
    int startMonth = (s - 1) * 3 + 1;
    int endMonth = s * 3;
    AQCondition q;
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // 当前城市
        for (int j = startMonth; j <= endMonth; j++) {
            int mmax = mList[j - 1];    // 该月天数
            // 读取该月每天的数据
            for (int k = 1; k <= mmax; k++) {
                if (p.AQCList[j - 1][k - 1].AQCdate.month != 0) {
                    q = p.AQCList[j - 1][k - 1];    // 当前城市当日空气质量数据
                    count += 1;
                    average += (double) q.index;
                }
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// 通过引用返回一整年各城市 城市名-平均空气质量指数
void yearAverageAQ(vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // 城市个数
    double average = 0; int count = 0;
    AQCondition q;
    // 遍历城市列表
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // 当前城市
        for (int j = 1; j <= 12; j++) {
            int mmax = mList[j - 1];    // 该月天数
            // 读取该月每天的数据
            for (int k = 1; k <= mmax; k++) {
                if (p.AQCList[j - 1][k - 1].AQCdate.month != 0) {
                    q = p.AQCList[j - 1][k - 1];    // 当前城市当日空气质量数据
                    count += 1;
                    average += (double) q.index;
                }
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// 插入排序
void insertSort(vector<cityAQC> &arr) {
    cityAQC temp; int i, j;
    for (i = 1; i <= arr.size() - 1; i++) {
        if (arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i-1; j >= 0 && temp < arr[j]; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

// 返回某城市在城市列表里的索引值
int findCity(vector<city> &cityList, string a) {
    int i = 0;
    for (i = 0; i < cityList.size(); i++) {
        if (cityList[i].name == a) return i;
    }
    cout << "未找到该城市！" << endl;
    return i;
}
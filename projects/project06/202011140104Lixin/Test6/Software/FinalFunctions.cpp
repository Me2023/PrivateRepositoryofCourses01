#include "city.cpp"

void normalSearch(city chosenCity) {
    int num1, num2; string kind;
    cout << "你要进行 日/周/月/年 查询？请输入:" << endl;
    cin >> kind;
    if (kind == "日") {
        cout << "请输入日期, 月和日以空格隔开 (如1月25日输入1 25):";
        cin >> num1 >> num2;
        cout << chosenCity.name; dateIn2006(num1, num2).display();
        cout << "的数据如下:" << endl;
        chosenCity.searchDayAQ(dateIn2006(num1, num2));
    }
    else if (kind == "周") {
        cout << "请输入要查询的周数 (不应超过52):";
        cin >> num1;
        cout << chosenCity.name << "第 " << num1 << " 周的数据如下:" << endl;
        chosenCity.searchWeekAQ(num1);
    }
    else if (kind == "月") {
        cout << "请输入要查询的月份:";
        cin >> num1;
        cout << chosenCity.name << num1 << " 月的数据如下:" << endl;
        chosenCity.searchMonthAQ(num1);
    }
    else if (kind == "季") {
        cout << "请输入要查询的季度 (1/2/3/4):";
        cin >> num1;
        cout << chosenCity.name << "第 " << num1 << " 季的数据如下:" << endl;
        chosenCity.searchSeasonAQ(num1);
    }
    else if (kind == "年") {
        cout << chosenCity.name << 2006 << " 年的数据如下:" << endl;
        chosenCity.searchYearAQ();
    }
}

void statisticalCitySearch(city chosenCity) {
    int num1, datas[5] = {0}; string kind;
    cout << "你要进行 周/月/年 查询？请输入:" << endl;
    cin >> kind;
    if (kind == "周") {
        cout << "请输入要查询的周数 (不应超过52):";
        cin >> num1;
        chosenCity.staSearchWeekAQ(num1, datas);
        cout << chosenCity.name << "第" << num1 << "周空气质量天数" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "优", "良", "轻微污染", "轻度污染", "重污染");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "月") {
        cout << "请输入要查询的月份:";
        cin >> num1;
        chosenCity.staSearchMonthAQ(num1, datas);
        cout << chosenCity.name << num1 << "月空气质量天数" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "优", "良", "轻微污染", "轻度污染", "重污染");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "季") {
        cout << "请输入要查询的季度 (1/2/3/4):";
        cin >> num1;
        chosenCity.staSearchSeasonAQ(num1, datas);
        cout << chosenCity.name << "第" << num1 << "季空气质量天数" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "优", "良", "轻微污染", "轻度污染", "重污染");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "年") {
        chosenCity.staSearchYearAQ(datas);
        cout << chosenCity.name << 2006 << "年空气质量天数" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "优", "良", "轻微污染", "轻度污染", "重污染");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
}

void statisticalTimeSearch(vector<city> &cityList) {
    int num1, level, min; string kind;
    string levelName[5] = {string("优"), string("良"), string("轻微污染"), string("轻度污染"), string("重污染")};
    vector<string> result;
    cout << "你要进行 周/月/年 查询？请输入:" << endl;
    cin >> kind;
    cout << "你要查询 1优/2良/3轻微污染/4轻度污染/5重污染 天数在几天以上的城市？请依次输入要查询的 类型序号 和 天数 并以空格隔开（例：“1 4”表示空气质量为优4天以上）:" << endl;
    cin >> level >> min;
    if (kind == "周") {
        cout << "请输入要查询的周数 (不应超过52):";
        cin >> num1;
        timeSearchWeekAQ(num1, level, min, cityList, result);
        cout << "2006年第" << num1 << "周空气质量为" << levelName[level - 1] << "在" << min << "天以上的城市有：" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "月") {
        cout << "请输入要查询的月份:";
        cin >> num1;
        timeSearchMonthAQ(num1, level, min, cityList, result);
        cout << "2006年第" << num1 << "月空气质量为" << levelName[level - 1] << "在" << min << "天以上的城市有：" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "季") {
        cout << "请输入要查询的季度 (1/2/3/4):";
        cin >> num1;
        timeSearchSeasonAQ(num1, level, min, cityList, result);
        cout << "2006年第" << num1 << "季度空气质量为" << levelName[level - 1] << "在" << min << "天以上的城市有：" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "年") {
        timeSearchYearAQ(level, min, cityList, result);
        cout << "2006年" << "空气质量为" << levelName[level - 1] << "在" << min << "天以上的城市有：" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
}

void sortSearch(vector<city> &cityList) {
    int num1; string kind;
    vector<cityAQC> result;
    cout << "你要进行 周/月/年 查询？请输入:" << endl;
    cin >> kind;
    if (kind == "周") {
        cout << "请输入要查询的周数 (不应超过52):";
        cin >> num1;
        weekAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006年第" << num1 << "周的平均空气质量排行榜（前20名）如下：" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "月") {
        cout << "请输入要查询的月份:";
        cin >> num1;
        monthAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006年第" << num1 << "月的平均空气质量排行榜（前20名）如下：" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "季") {
        cout << "请输入要查询的季度 (1/2/3/4):";
        cin >> num1;
        seasonAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006年第" << num1 << "季度的平均空气质量排行榜（前20名）如下：" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "年") {
        yearAverageAQ(cityList, result);
        insertSort(result);
        cout << "2006年的平均空气质量排行榜（前20名）如下：" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
}
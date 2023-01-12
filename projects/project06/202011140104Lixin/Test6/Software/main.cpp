#include "FinalFunctions.cpp"

int main() {
    // 数据读取
    vector<city> cityList;
    readAQCs("data.txt", cityList); // 该txt相比最原始的，编码由ANSI改为GB2312
    // 程序开始
    int num, i; string cityName; city p;
    printf("你要进行 1普通查询/2统计查询/3排序查询？请输入序号：");
    cin >> num;
    if (num == 1) {
        printf("已进入普通查询。你要查询哪个城市？请输入城市名：");
        cin >> cityName;
        i = findCity(cityList, cityName);
        p = cityList[i];
        normalSearch(p);
    }
    else if (num == 2) {
        printf("已进入统计查询。接下来你要进行 1城市查询/2时间查询？请输入序号：");
        cin >> num;
        if (num == 1) {
            printf("你要查询哪个城市？请输入城市名：");
            cin >> cityName;
            i = findCity(cityList, cityName);
            p = cityList[i];
            statisticalCitySearch(p);
        }
        else if (num == 2) {
            statisticalTimeSearch(cityList);
        }
    }
    else if (num == 3) {
        printf("已进入排序查询。\n");
        sortSearch(cityList);
    }

    cin >> num;     // 避免最后运行完便闪退
}
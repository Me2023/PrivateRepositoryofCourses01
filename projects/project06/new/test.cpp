#include "FinalFunctions.cpp"
using namespace std;
 
int main () {
    vector<city> cityList;
    readAQCs("data.txt", cityList); // 该txt相比最原始的，编码由ANSI改为UTF-8
    int num[5] = {0};
    cityList[1].searchMonthAQ(10);
    cityList[1].staSearchMonthAQ(10, num);
    cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << endl;

    // cityList[1].searchMonthAQ(1);
    // cityList[2].searchYearAQ();
    /* 
    vector<string> str;
    timeSearchYearAQ(1, 30, cityList, str);
    int max = str.size();
    for (int i = 0; i < max; i++) {
        cout << str[i] << " ";
    }
    cout << endl;*/

    vector<cityAQC> result;
    yearAverageAQ(cityList, result);
    insertSort(result);
    int n = result.size();
    for (int i = 0; i < n; i++) {
        cout << result[i].name << '\t' << result[i].averageAQ << endl;
    }

    // normalSearch(cityList[0]);
    // statisticalCitySearch(cityList[1]);

    // statisticalTimeSearch(cityList);

    sortSearch(cityList);
    return 0;
}
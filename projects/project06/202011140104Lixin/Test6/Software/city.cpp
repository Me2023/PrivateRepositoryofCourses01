#include "AQCondition.cpp"

class city {
public:
    int num;                        // �������
    string name;                    // ������
    AQCondition AQCList[12][31];    // �ó��ж�Ӧ�����п�������״��������ɵĶ�ά����

    // ���캯��
    city(int a = 0, string b = "") 
    : num(a), name(b) {} 

    
    /* ��ͨ��ѯ���ֱ��ѯ�ó���ÿ�졢ÿ�ܡ�ÿ�¡�ÿ���Ⱥ�ȫ��Ŀ�������״�� */
    // ��ѯ�ó���ÿ��Ŀ�������״��
    void searchDayAQ(dateIn2006 d) {
        int mm = d.month, dd = d.day;
        AQCList[mm - 1][dd - 1].display();
    }

    // ��ѯ�ó���ÿ�ܵĿ�������״��
    void searchWeekAQ(int w) {
        vector<dateIn2006> dateList;
        daysOfWeek(w, dateList);
        dateIn2006 now;
        int max = dateList.size();
        int i = 0;
        for (i = 0; i < max; i++) {
            now = dateList[i]; // ����
            // now.display();
            if (AQCList[now.month - 1][now.day - 1].AQCdate.month == 0) {
                cout << name << " �� "; now.display(); cout << " û�����ݣ�" << endl;
            }
            else {
                AQCList[now.month - 1][now.day - 1].display();
            }
        }
    }

    // ��ѯ�ó���ÿ�µĿ�������״��
    void searchMonthAQ(int m) {
        int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int max = mList[m - 1]; // ��������
        for (int i = 1; i <= max; i++) {
            if (AQCList[m - 1][i - 1].AQCdate.month == 0) {
                cout << name << " �� "; dateIn2006(m, i).display(); cout << " û�����ݣ�" << endl;
            }
            else {
                AQCList[m - 1][i - 1].display();
            }
        }
    }

    // ��ѯ�ó���ÿ���ȵĿ�������״��
    void searchSeasonAQ(int s) {
        int startMonth = (s - 1) * 3 + 1;
        int endMonth = s * 3;
        for (int i = startMonth; i <= endMonth; i++) {
            searchMonthAQ(i);
        }
    }

    // ��ѯ�ó���һ����Ŀ�������״��
    void searchYearAQ() {
        for (int i = 1; i <= 4; i++) {
            searchSeasonAQ(i);
        }
    }

    /* ͳ�Ʋ�ѯ��ͨ�����鷵�ظ�����������Ӧ������ */
    // ͳ�Ʋ�ѯ�ó���ĳ�ܵĿ�������״�����������ͨ�����鷵��
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
                if (p.degree == "��") {
                    num[0] += 1;
                }
                else if (p.degree == "��") {
                    num[1] += 1;
                }
                else if (p.degree == "��΢��Ⱦ") {
                    num[2] += 1;
                }
                else if (p.degree == "�����Ⱦ") {
                    num[3] += 1;
                }
                else if (p.degree == "����Ⱦ" || p.degree == "�ж�����Ⱦ") {
                    num[4] += 1;
                }
            }
        }
    }
    // ͳ�Ʋ�ѯ�ó���ĳ�µĿ�������״�������ͨ�����鷵��
    void staSearchMonthAQ(int m, int num[5] = {0}) {
        int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int max = mList[m - 1]; // ��������
        AQCondition p;
        for (int i = 1; i <= max; i++) {
            if (AQCList[m - 1][i - 1].AQCdate.month != 0) {
                p = AQCList[m - 1][i - 1];
                if (p.degree == "��") {
                    num[0] += 1;
                }
                else if (p.degree == "��") {
                    num[1] += 1;
                }
                else if (p.degree == "��΢��Ⱦ") {
                    num[2] += 1;
                }
                else if (p.degree == "�����Ⱦ") {
                    num[3] += 1;
                }
                else if (p.degree == "����Ⱦ") {
                    num[4] += 1;
                }
            }
        }
    }

    // ͳ�Ʋ�ѯ�ó���ĳ���ȵĿ�������״�������ͨ�����鷵��
    void staSearchSeasonAQ(int s, int num[5] = {0}) {
        int startMonth = (s - 1) * 3 + 1;
        int endMonth = s * 3;
        for (int i = startMonth; i <= endMonth; i++) {
            staSearchMonthAQ(i, num);
        }
    }

    // ͳ�Ʋ�ѯ�ó���һ����Ŀ�������״�������ͨ�����鷵��
    void staSearchYearAQ(int num[5] = {0}) {
        for (int i = 1; i <= 4; i++) {
            staSearchSeasonAQ(i, num);
        }
    }

};



// ��ȡtxt�ļ��������������ݴ��浽���ж�����ɵ�vector��
void readAQCs(string txt, vector<city> &cityList) {
    string data;
    string strs[4];
    int nums[5];
    int preNum = 0, curNum = 0; string curName = "";
    city newCity = city();
    // ���ļ�
    ifstream infile; 
    infile.open(txt); 
    int i = 0;
    // ��ʼ��ȡ
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
        // ����һ�У���������ݵ������б�
        curNum = nums[0]; curName = strs[0];
        if (curNum != preNum) {
            // �����ǰһ�����ݵĳ��в�ͬ��������³��У��������п����������ݴ���ó��ж��������������
            newCity = city(curNum, curName);
            newCity.AQCList[nums[3] - 1][nums[4] - 1] = AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]);
            cityList.push_back(newCity);
        }
        else {
            // �������ͬһ���У������п����������ݴ���ó��ж�����
            cityList.back().AQCList[nums[3] - 1][nums[4] - 1] = AQCondition(nums[0], strs[0], strs[1], nums[1], 
        strs[2], strs[3], nums[3], nums[4]);
        }
        preNum = curNum;
        // cityList.back().AQCList[nums[3] - 1][nums[4] - 1].display();
    }
 
    infile.close();
    return;
}

/* ͳ�Ʋ�ѯ 2������ʱ���ѯ��������״�� */
// ��ѯĳ��ĳ��������״��������� min �ĳ��У�������ͨ�� result ���ء�
void timeSearchWeekAQ(int w, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // ���и���
    city p;
    int num[5] = {0};
    // ���������б�
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

// ��ѯĳ��ĳ��������״��������� min �ĳ��У�������ͨ�� result ���ء�
void timeSearchMonthAQ(int m, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // ���и���
    city p;
    int num[5] = {0};
    // ���������б�
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

// ��ѯĳ����ĳ��������״��������� min �ĳ��У�������ͨ�� result ���ء�
void timeSearchSeasonAQ(int s, int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // ���и���
    city p;
    int num[5] = {0};
    // ���������б�
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

// ��ѯһ����ĳ��������״��������� min �ĳ��У�������ͨ�� result ���ء�
void timeSearchYearAQ(int level, int min, vector<city> &cityList, vector<string> &result) {
    int max = cityList.size(); // ���и���
    city p;
    int num[5] = {0};
    // ���������б�
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


/* �����ѯ�������ܱ�š��±�š����ȱ�Ż����ţ���ѯ���п������������а� */

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

// ͨ�����÷���ĳ�ܸ����� ������-ƽ����������ָ�� ��ɵ� cityAQC ��� vector
void weekAverageAQ(int w, vector<city> &cityList, vector<cityAQC> &result) {
    int max = cityList.size(); // ���и���
    double average = 0; int count = 0;
    vector<dateIn2006> dateList;
    daysOfWeek(w, dateList); dateIn2006 now; AQCondition q;
    // ���������б�
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // ��ǰ����
        int mmax = dateList.size();     // ��������
        // ��ȡ����ÿ�������
        for (int j = 0; j < mmax; j++) {
            now = dateList[j];
            if (p.AQCList[now.month - 1][now.day - 1].AQCdate.month != 0) {
                q = p.AQCList[now.month - 1][now.day - 1]; // ��ǰ���е��տ�����������
                average += (double) q.index;
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// ͨ�����÷���ĳ�¸����� ������-ƽ����������ָ��
void monthAverageAQ(int m, vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // ���и���
    double average = 0; int count = 0;
    AQCondition q;
    // ���������б�
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // ��ǰ����
        int mmax = mList[m - 1];    // ��������
        // ��ȡ����ÿ�������
        for (int j = 1; j <= mmax; j++) {
            if (p.AQCList[m - 1][j - 1].AQCdate.month != 0) {
                q = p.AQCList[m - 1][j - 1];    // ��ǰ���е��տ�����������
                count += 1;
                average += (double) q.index;
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// ͨ�����÷���ĳ���ȸ����� ������-ƽ����������ָ��
void seasonAverageAQ(int s, vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // ���и���
    double average = 0; int count = 0;
    int startMonth = (s - 1) * 3 + 1;
    int endMonth = s * 3;
    AQCondition q;
    // ���������б�
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // ��ǰ����
        for (int j = startMonth; j <= endMonth; j++) {
            int mmax = mList[j - 1];    // ��������
            // ��ȡ����ÿ�������
            for (int k = 1; k <= mmax; k++) {
                if (p.AQCList[j - 1][k - 1].AQCdate.month != 0) {
                    q = p.AQCList[j - 1][k - 1];    // ��ǰ���е��տ�����������
                    count += 1;
                    average += (double) q.index;
                }
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// ͨ�����÷���һ��������� ������-ƽ����������ָ��
void yearAverageAQ(vector<city> &cityList, vector<cityAQC> &result) {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = cityList.size();      // ���и���
    double average = 0; int count = 0;
    AQCondition q;
    // ���������б�
    for (int i = 0; i < max; i++) {
        city p = cityList[i];            // ��ǰ����
        for (int j = 1; j <= 12; j++) {
            int mmax = mList[j - 1];    // ��������
            // ��ȡ����ÿ�������
            for (int k = 1; k <= mmax; k++) {
                if (p.AQCList[j - 1][k - 1].AQCdate.month != 0) {
                    q = p.AQCList[j - 1][k - 1];    // ��ǰ���е��տ�����������
                    count += 1;
                    average += (double) q.index;
                }
            }
        }
        result.push_back(cityAQC(q.name, average / count));
        average = 0; count = 0;
    }
}

// ��������
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

// ����ĳ�����ڳ����б��������ֵ
int findCity(vector<city> &cityList, string a) {
    int i = 0;
    for (i = 0; i < cityList.size(); i++) {
        if (cityList[i].name == a) return i;
    }
    cout << "δ�ҵ��ó��У�" << endl;
    return i;
}
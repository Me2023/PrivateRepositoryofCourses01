#include "city.cpp"

void normalSearch(city chosenCity) {
    int num1, num2; string kind;
    cout << "��Ҫ���� ��/��/��/�� ��ѯ��������:" << endl;
    cin >> kind;
    if (kind == "��") {
        cout << "����������, �º����Կո���� (��1��25������1 25):";
        cin >> num1 >> num2;
        cout << chosenCity.name; dateIn2006(num1, num2).display();
        cout << "����������:" << endl;
        chosenCity.searchDayAQ(dateIn2006(num1, num2));
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ������ (��Ӧ����52):";
        cin >> num1;
        cout << chosenCity.name << "�� " << num1 << " �ܵ���������:" << endl;
        chosenCity.searchWeekAQ(num1);
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ���·�:";
        cin >> num1;
        cout << chosenCity.name << num1 << " �µ���������:" << endl;
        chosenCity.searchMonthAQ(num1);
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ�ļ��� (1/2/3/4):";
        cin >> num1;
        cout << chosenCity.name << "�� " << num1 << " ������������:" << endl;
        chosenCity.searchSeasonAQ(num1);
    }
    else if (kind == "��") {
        cout << chosenCity.name << 2006 << " �����������:" << endl;
        chosenCity.searchYearAQ();
    }
}

void statisticalCitySearch(city chosenCity) {
    int num1, datas[5] = {0}; string kind;
    cout << "��Ҫ���� ��/��/�� ��ѯ��������:" << endl;
    cin >> kind;
    if (kind == "��") {
        cout << "������Ҫ��ѯ������ (��Ӧ����52):";
        cin >> num1;
        chosenCity.staSearchWeekAQ(num1, datas);
        cout << chosenCity.name << "��" << num1 << "�ܿ�����������" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "��", "��", "��΢��Ⱦ", "�����Ⱦ", "����Ⱦ");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ���·�:";
        cin >> num1;
        chosenCity.staSearchMonthAQ(num1, datas);
        cout << chosenCity.name << num1 << "�¿�����������" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "��", "��", "��΢��Ⱦ", "�����Ⱦ", "����Ⱦ");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ�ļ��� (1/2/3/4):";
        cin >> num1;
        chosenCity.staSearchSeasonAQ(num1, datas);
        cout << chosenCity.name << "��" << num1 << "��������������" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "��", "��", "��΢��Ⱦ", "�����Ⱦ", "����Ⱦ");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
    else if (kind == "��") {
        chosenCity.staSearchYearAQ(datas);
        cout << chosenCity.name << 2006 << "�������������" << endl;
        printf("%-12s\t%-12s\t%-12s\t%-12s\t%-12s\n", "��", "��", "��΢��Ⱦ", "�����Ⱦ", "����Ⱦ");
        printf("%-12d\t%-12d\t%-12d\t%-12d\t%-12d\n", datas[0], datas[1], datas[2], datas[3], datas[4]);
    }
}

void statisticalTimeSearch(vector<city> &cityList) {
    int num1, level, min; string kind;
    string levelName[5] = {string("��"), string("��"), string("��΢��Ⱦ"), string("�����Ⱦ"), string("����Ⱦ")};
    vector<string> result;
    cout << "��Ҫ���� ��/��/�� ��ѯ��������:" << endl;
    cin >> kind;
    cout << "��Ҫ��ѯ 1��/2��/3��΢��Ⱦ/4�����Ⱦ/5����Ⱦ �����ڼ������ϵĳ��У�����������Ҫ��ѯ�� ������� �� ���� ���Կո������������1 4����ʾ��������Ϊ��4�����ϣ�:" << endl;
    cin >> level >> min;
    if (kind == "��") {
        cout << "������Ҫ��ѯ������ (��Ӧ����52):";
        cin >> num1;
        timeSearchWeekAQ(num1, level, min, cityList, result);
        cout << "2006���" << num1 << "�ܿ�������Ϊ" << levelName[level - 1] << "��" << min << "�����ϵĳ����У�" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ���·�:";
        cin >> num1;
        timeSearchMonthAQ(num1, level, min, cityList, result);
        cout << "2006���" << num1 << "�¿�������Ϊ" << levelName[level - 1] << "��" << min << "�����ϵĳ����У�" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ�ļ��� (1/2/3/4):";
        cin >> num1;
        timeSearchSeasonAQ(num1, level, min, cityList, result);
        cout << "2006���" << num1 << "���ȿ�������Ϊ" << levelName[level - 1] << "��" << min << "�����ϵĳ����У�" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
    else if (kind == "��") {
        timeSearchYearAQ(level, min, cityList, result);
        cout << "2006��" << "��������Ϊ" << levelName[level - 1] << "��" << min << "�����ϵĳ����У�" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " "; 
        }
        cout << endl;
    }
}

void sortSearch(vector<city> &cityList) {
    int num1; string kind;
    vector<cityAQC> result;
    cout << "��Ҫ���� ��/��/�� ��ѯ��������:" << endl;
    cin >> kind;
    if (kind == "��") {
        cout << "������Ҫ��ѯ������ (��Ӧ����52):";
        cin >> num1;
        weekAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006���" << num1 << "�ܵ�ƽ�������������а�ǰ20�������£�" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ���·�:";
        cin >> num1;
        monthAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006���" << num1 << "�µ�ƽ�������������а�ǰ20�������£�" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "��") {
        cout << "������Ҫ��ѯ�ļ��� (1/2/3/4):";
        cin >> num1;
        seasonAverageAQ(num1, cityList, result);
        insertSort(result);
        cout << "2006���" << num1 << "���ȵ�ƽ�������������а�ǰ20�������£�" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
    else if (kind == "��") {
        yearAverageAQ(cityList, result);
        insertSort(result);
        cout << "2006���ƽ�������������а�ǰ20�������£�" << endl;
        for(int i = 0; i < 20; i++) {
            printf("%-12s\t%-12f\n", result[i].name.c_str(), result[i].averageAQ);
        }
    }
}
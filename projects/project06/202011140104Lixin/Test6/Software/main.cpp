#include "FinalFunctions.cpp"

int main() {
    // ���ݶ�ȡ
    vector<city> cityList;
    readAQCs("data.txt", cityList); // ��txt�����ԭʼ�ģ�������ANSI��ΪGB2312
    // ����ʼ
    int num, i; string cityName; city p;
    printf("��Ҫ���� 1��ͨ��ѯ/2ͳ�Ʋ�ѯ/3�����ѯ����������ţ�");
    cin >> num;
    if (num == 1) {
        printf("�ѽ�����ͨ��ѯ����Ҫ��ѯ�ĸ����У��������������");
        cin >> cityName;
        i = findCity(cityList, cityName);
        p = cityList[i];
        normalSearch(p);
    }
    else if (num == 2) {
        printf("�ѽ���ͳ�Ʋ�ѯ����������Ҫ���� 1���в�ѯ/2ʱ���ѯ����������ţ�");
        cin >> num;
        if (num == 1) {
            printf("��Ҫ��ѯ�ĸ����У��������������");
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
        printf("�ѽ��������ѯ��\n");
        sortSearch(cityList);
    }

    cin >> num;     // ������������������
}
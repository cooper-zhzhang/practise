#include <iostream>
using namespace std;

int main()
{
	int i = 66;
	int j; //����Դ
	int k; //΢��֧������
	int l; //����֧������
	int m;//ȫ���
	int n;//�����̳� �Ƿ� setting mode 0 δ����
	string XR_STORE[3] = {"XR_STORE", "XR_DOCTOR", "XR_CLINIC"};//����Դ
	string paytype1[3] = {"WECHAT_JS",  "WECHAT_CODE", "DR_WECHAT_JS", };//΢��֧������3��
	string paytype2[4] = {"COUPON", "ALLOWANCE", "EXPERIENCE", "DOCTOR_BENEFIT"};//����֧������
//	for(i = 11; i < 200; ++i)
	{
		for(j = 0; j < 3; ++j)
			for(k = 0; k < 3; ++k)
				for(l = 0; l < 4; ++l)
					for(m = 0; m < 2; ++m)
						for(n = 0; n < 2; ++n)
				{
				i++;
					
				cout <<"/*" << endl;
				cout <<" *" ;

				cout <<"��������+����֧��+΢��֧��+����Դ+���:";
				if(l == 0)
					cout <<"�Ż�ȯ";
				else if(l == 1)
					cout <<"����";
				else if(l == 2)
					cout <<"�����";
				else if(l == 3)
					cout <<"ҽ���Ż�";

				cout <<"+";
				if(k == 0)
					cout <<"΢��H5֧��";
				else if(k == 1)
					cout <<"΢�Ŷ�ά��";
				else if(k == 2)
					cout <<"ҽ��΢��H5";

				cout <<"+";

				if(j == 0)
					cout <<"�����̳�";
				else if(j == 1)
					cout <<"����ҽ��";
				else if(j == 2)
					cout <<"��������";

				cout <<"+";
				if(m == 0)
					cout <<"ȫ��";
				else
					cout <<"����";


				
				cout << endl;
				cout <<  "*/" << endl;
				if(m == 1 || (j == 0 && n ==0))
					cout <<"@Test(expected = ApiException.class)"<<endl;
				else
					cout <<"@Test"<<endl;
				cout <<"@Transactional"<<endl;
				if(i < 100)
					cout <<"public void test0"<<i<<"do_Pay() {"<<endl;
				else
					cout <<"public void test"<<i<<"do_Pay() {"<<endl;
					cout <<"  Order order = createOrder(OrderSource."<<XR_STORE[j]<<");"<<endl;
					if(m == 0)
					{
						cout <<"  PaymentCreateForm payment1 = createPaymentForm("<<paytype1[k]<<", order.getRealFee()/2);"<<endl;
						cout <<"  PaymentCreateForm payment2 = createPaymentForm("<<paytype2[l]<<", order.getRealFee()-order.getRealFee()/2);"<<endl;
					}
					else
					{
						cout <<"  PaymentCreateForm payment1 = createPaymentForm("<<paytype1[k]<<", order.getRealFee()/4);"<<endl;
						cout <<"  PaymentCreateForm payment2 = createPaymentForm("<<paytype2[l]<<", order.getRealFee()/4);"<<endl;
					}

					cout <<"  PaymentsCreateForm from = new PaymentsCreateForm();"<<endl;
					cout <<"  from.setOrderNo(order.getOrderNo());"<<endl;
					cout <<"  from.getPayments().add(payment1);"<<endl;
					cout <<"  from.getPayments().add(payment2);"<<endl;
					cout <<"  payService.doPay(from);"<<endl;
					cout <<"  checkPay(order.getId(), 0L, UNPAID, false, order.getRealFee());"<<endl;
					cout <<"}"<<endl;
				}
 }


	return 0;
}

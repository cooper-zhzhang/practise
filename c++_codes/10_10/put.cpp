#include <iostream>
using namespace std;

int main()
{
	int i = 66;
	int j; //订单源
	int k; //微信支付类型
	int l; //虚拟支付类型
	int m;//全额部分
	int n;//杏仁商城 是否 setting mode 0 未设置
	string XR_STORE[3] = {"XR_STORE", "XR_DOCTOR", "XR_CLINIC"};//订单源
	string paytype1[3] = {"WECHAT_JS",  "WECHAT_CODE", "DR_WECHAT_JS", };//微信支付类型3种
	string paytype2[4] = {"COUPON", "ALLOWANCE", "EXPERIENCE", "DOCTOR_BENEFIT"};//虚拟支付类型
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

				cout <<"创建订单+虚拟支付+微信支付+订单源+金额:";
				if(l == 0)
					cout <<"优惠券";
				else if(l == 1)
					cout <<"补贴";
				else if(l == 2)
					cout <<"体验金";
				else if(l == 3)
					cout <<"医生优惠";

				cout <<"+";
				if(k == 0)
					cout <<"微信H5支付";
				else if(k == 1)
					cout <<"微信二维码";
				else if(k == 2)
					cout <<"医生微信H5";

				cout <<"+";

				if(j == 0)
					cout <<"杏仁商城";
				else if(j == 1)
					cout <<"杏仁医生";
				else if(j == 2)
					cout <<"杏仁门诊";

				cout <<"+";
				if(m == 0)
					cout <<"全额";
				else
					cout <<"部分";


				
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

///THIS BASE POWERER BY SONARADAR ELECTRONIC INC.ALL RIGHTS RESERVED.
///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

///final version.do not distribute！
///final version.do not distribute！
///final version.do not distribute！


///头文件部分
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h> 
#pragma warning(disable:4996)///防止 sys_My_date_getcurrentdate() 报错
using namespace std;
///结构设
///时间结构体，这个是用来储存时间的，
///mydate.year 表示年，月、日以此类推
struct My_Date {
	int year;
	int month;
	int day;
};
///商品数据结构体
struct ProductItem
{
	int ProductID;///商品编号
	string ProductName;///商品名称
	float ProductPrice;///商品价格，支持小数点
	float ProductCost;///商品成本，支持小数点
	struct My_Date ProductManufactureDate;///商品生产日期，转换成天数表示
	struct My_Date ProductGuaranteePeriod;///商品到期日期
	float ProductDiscount;///商品折扣，如95折就是0.95，不打折直接输入1;
	string ProductOrigin;///商品生产地
	string ProductBatch;///商品生产批次
	string ProductProducer;///商品生产商
	string ProductShelf;///所在货架号
	string ProductDetails;///所在货架号
};
///反馈单结构体
struct RequsetForm {
	int id = 0;
	int requestClass = 0;
	string name = "";
	string contractway = "";
	string request = "";
	bool isResponded = false;
	bool isAgree = false;
	string responder = "";
	string result = "";
};
///函数声明
///这个函数是用来输入测试数据用的
void sys_testinput_setdata(int index, int id, string name, float price, long long mdate, long long gperiod, float discount, string origin, string batch, string producer, string shelf, string details);
///这个是用来设置日期结构体日期的，这样方便点，要不写三行太麻烦
My_Date sys_setMy_date(int year, int month, int day, My_Date targetd);
///编写功能
///
///这些函数功能请从后面对应看功能

int func_querysystem();
void func_ShowProductInfo();
void func_InsertProduct();
void func_DeleteProduct();
void func_SearchProduct();
void func_EditProduct();
void func_SortProduct();

void func_SearchProduct_byname();
void func_SearchProduct_byid();
void func_SearchProduct_bydiscount();
void func_SearchProduct_bypricesection();
void func_SearchProduct_byproducer();
void func_SearchProduct_byshelf();
void func_SearchProduct_bydate();
void func_SearchProduct_byoverdate();
void func_SearchProduct_byprofitsection();

void func_SortProduct_byid_up();
void func_SortProduct_byid_down();
void func_SortProduct_bypriceori_up();
void func_SortProduct_bypriceori_down();
void func_SortProduct_bypricemod_up();
void func_SortProduct_bypricemod_down();
void func_SortProduct_bydiscount_up();
void func_SortProduct_bydiscount_down();
void func_SortProduct_byprofit_up();
void func_SortProduct_byprofit_down();
void func_SortProduct_bycost_up();
void func_SortProduct_bycost_down();

///
void func_producer();
void func_discount();
void sys_discount_1(int n);
void func_cus_cd();
void func_cus_ShowProductInfo();
void func_cus_SearchProduct();
void func_cus_SearchProduct_byname();
void func_cus_SearchProduct_bydiscount();
void func_cus_SearchProduct_byproducer();
void func_cus_SearchProduct_byshelf();
void func_SearchProduct_bycostsection();
void func_cus_discount();
void func_cus_producer();
void  func_welcome_cd();
bool func_login();

void func_cus_requset();
void func_cus_request_create();
void func_cus_request_create_1();
void func_cus_request_create_2();
void func_cus_request_create_3();
void func_cus_request_create_4();
void func_cus_request_create_5();
void func_cus_request_create_6();
void func_cus_request_create_7();
void func_cus_request_create_8();
void func_cus_requsetview(int id);
void func_cus_request_findrequest_byid();
void func_requset();
void func_requset_manager_all();
void func_request_viewer_all(int id);
void func_requsetview_all(int id);
void func_requsetview_reply_all(int id);
void func_requset_manager_fininshed();
void func_request_viewer_fininshed(int id);
void func_requsetview_fininshed(int id);
void func_requset_manager_unfinished();
void func_request_viewer_unfinished(int id);
void func_requsetview_unfinished(int id);
void func_requsetview_reply_unfinished(int id);

///变量声明
ProductItem product[10001];///使用数组，预设最大10000个货物，数组0不使用
RequsetForm request[10001];///使用数组，预设最大10000个反馈单，数组0不使用
const string pwd = "123456";///这个是登录系统的秘钥，可以修改的

///注意，以下代码为架构代码，请勿修改
//有魔法，别碰。
//有魔法，别碰。
//有魔法，别碰。
//重要事情说三遍！！！！！！！！！！
///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

///判断两个日期间隔多少天
///用法sys_getday(起始日期，结束日期)  [均是My_Date结构体型]
///返回 间隔日期 long long 型
long long sys_getday(My_Date s_date, My_Date m_date) {
	int sy = s_date.year, sm = s_date.month, sd = s_date.day, ey = m_date.year, em = m_date.month, ed = m_date.day, C = 0;
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (ey - sy == 0) {
		if ((sy % 4 == 0 && sy % 100 != 0) || (sy % 400 == 0)) {
			m[2] = 29;
		}
		for (int i = sm; i < em; i++) {
			if (i == sm) {
				C = m[i] - sd;
			}
			else {
				C += m[i];
			}
		}
		C += ed;
		if (sm == em) {
			C = ed - sd;
		}
	}
	else {
		for (int i = sy; i < ey; i++) {
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
				C += 366;
			}
			else {
				C += 365;
			}
		}
		if (sy % 4 == 0 && sy % 100 != 0 || sy % 400 == 0) {
			m[2] = 29;
		}
		for (int i = 1; i < sm; i++) {
			C -= m[i];
		}
		C -= sd;
		if (ey % 4 == 0 && ey % 100 != 0 || ey % 400 == 0) {
			m[2] = 29;
		}
		else {
			m[2] = 28;
		}
		for (int i = 1; i < em; i++) {
			C += m[i];
		}
		C += ed;
	}
	return C;
}
///设置初始数据 这个功能用于导入初始数据
///用法sys_testinput_setdata(序号[int]，货物编号[int]，货物名称[string]，货物价格[float]，货物生产日期[My_Date]，货物到期日期[My_Date]，货物折扣[float]，货物原产地[string]，货物批次[string]，货物生产商[string]，货物货架号[string]，货物描述细节[string])
///无返回值
void sys_testinput_setdata(int index, int id, string name, float price, My_Date mdate, My_Date gperiod, float discount, string origin, string batch, string producer, string shelf, string details) {
	product[index].ProductID = id;
	product[index].ProductName = name;
	product[index].ProductPrice = price;
	product[index].ProductManufactureDate = mdate;
	product[index].ProductGuaranteePeriod = gperiod;
	product[index].ProductDiscount = discount;
	product[index].ProductOrigin = origin;
	product[index].ProductBatch = batch;
	product[index].ProductProducer = producer;
	product[index].ProductShelf = shelf;
	product[index].ProductDetails = details;
}
///在My_Date型设置日期
///sys_setMy_date(年[int型]，月[int型]，日[int型])
///返回 My_date 格式日期
My_Date sys_setMy_date(int year, int month, int day) {
	My_Date targetd;
	targetd.year = year;
	targetd.month = month;
	targetd.day = day;
	return targetd;
}
My_Date sys_My_date_getcurrentdate() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return sys_setMy_date(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
}

///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

///
///

///获取My_Date型文本
///sys_My_date_tostring(My_Date型)
///返回 string文本 如 2022-01-01
string sys_My_date_tostring(My_Date targetd) {
	if (targetd.month <= 10) {
		return (to_string(targetd.year) + "-0" + to_string(targetd.month) + "-" + to_string(targetd.day));
	}
	if (targetd.day <= 10) {
		return (to_string(targetd.year) + "-" + to_string(targetd.month) + "-0" + to_string(targetd.day));
	}
	if (targetd.month <= 10 && targetd.day <= 10) {
		return (to_string(targetd.year) + "-0" + to_string(targetd.month) + "-0" + to_string(targetd.day));
	}
	return (to_string(targetd.year) + "-" + to_string(targetd.month) + "-" + to_string(targetd.day));
}

///设置演示数据 
///用法 略
void sys_test_setdb() {
	sys_testinput_setdata(1, 2002301, "娃哈哈桂阅逐子八宝粥", 3.2, sys_setMy_date(2022, 3, 1), sys_setMy_date(2022, 8, 2), 0.95, "杭州", "294312", "江苏雨润食品产业集团有限公司", "A-01-1", "娃哈哈桂阅逐子八宝粥");

	sys_testinput_setdata(2, 2002301, "50Onl娃哈哈非常冰红茶", 2.4, sys_setMy_date(2022, 3, 3), sys_setMy_date(2022, 8, 4), 0.95, "杭州", "294313", "江苏雨润食品产业集团有限公司", "A-01-1", "50Onl娃哈哈非常冰红茶");

	sys_testinput_setdata(3, 2002301, "280n1娃哈哈营养快线《隙味)", 2.5, sys_setMy_date(2022, 3, 5), sys_setMy_date(2022, 8, 15), 0.95, "杭州", "294314", "江苏雨润食品产业集团有限公司", "A-01-1", "280n1娃哈哈营养快线《隙味)");

	sys_testinput_setdata(4, 2002301, "280n1娃哈哈菅养快线《菠萝)", 2.5, sys_setMy_date(2022, 3, 7), sys_setMy_date(2022, 8, 17), 0.95, "杭州", "294315", "江苏雨润食品产业集团有限公司", "A-01-1", "280n1娃哈哈菅养快线《菠萝)");

	sys_testinput_setdata(5, 2002301, "500n1娃哈哈营养快线(隙味》", 3.95, sys_setMy_date(2022, 3, 9), sys_setMy_date(2022, 8, 13), 0.95, "杭州", "294316", "江苏雨润食品产业集团有限公司", "A-01-1", "500n1娃哈哈营养快线(隙味》");

	sys_testinput_setdata(6, 2002301, "50onl娃哈哈营养快线(菠萝)", 3.9, sys_setMy_date(2022, 2, 11), sys_setMy_date(2022, 8, 15), 0.95, "杭州", "294317", "江苏雨润食品产业集团有限公司", "A-01-1", "50onl娃哈哈营养快线(菠萝)");

	sys_testinput_setdata(7, 2002301, "350n1呦呦奶荼(愿味》", 3.2, sys_setMy_date(2022, 2, 13), sys_setMy_date(2022, 8, 17), 0.95, "杭州", "294318", "江苏雨润食品产业集团有限公司", "A-01-1", "350n1呦呦奶荼(愿味》");

	sys_testinput_setdata(8, 2002301, "350al呦呦奶茶(桂花》", 3.2, sys_setMy_date(2022, 2, 15), sys_setMy_date(2022, 8, 19), 0.95, "杭州", "294319", "江苏雨润食品产业集团有限公司", "A-01-1", "350al呦呦奶茶(桂花》");

	sys_testinput_setdata(9, 2002301, "350ml呦呦奶茶(装莉〉", 3.2, sys_setMy_date(2022, 2, 17), sys_setMy_date(2022, 8, 21), 0.95, "杭州", "294320", "江苏雨润食品产业集团有限公司", "A-01-1", "350ml呦呦奶茶(装莉〉");

	sys_testinput_setdata(10, 2002301, "王老吉凉茶", 2.1, sys_setMy_date(2022, 2, 19), sys_setMy_date(2022, 8, 23), 0.95, "广州", "294321", "江苏雨润食品产业集团有限公司", "A-01-1", "王老吉凉茶");

	sys_testinput_setdata(11, 2002301, "355A1可口可乐", 1.9, sys_setMy_date(2022, 2, 21), sys_setMy_date(2022, 8, 2), 0.95, "杭州", "294322", "江苏雨润食品产业集团有限公司", "A-01-1", "355A1可口可乐");

	sys_testinput_setdata(12, 2002301, "355al雪碧", 1.9, sys_setMy_date(2022, 4, 23), sys_setMy_date(2022, 8, 4), 0.95, "杭州", "294323", "江苏雨润食品产业集团有限公司", "A-02-2", "355al雪碧");

	sys_testinput_setdata(13, 2002301, "355m1醒目[苹果〕", 3.5, sys_setMy_date(2022, 4, 25), sys_setMy_date(2022, 8, 15), 0.95, "杭州", "294324", "江苏雨润食品产业集团有限公司", "A-02-3", "355m1醒目[苹果〕");

	sys_testinput_setdata(14, 2002301, "355nl醒目[西瓜〕", 3.5, sys_setMy_date(2022, 4, 27), sys_setMy_date(2022, 8, 17), 0.95, "杭州", "294325", "江苏雨润食品产业集团有限公司", "A-02-4", "355nl醒目[西瓜〕");

	sys_testinput_setdata(15, 2002301, "60Cnl雪碧", 2.5, sys_setMy_date(2022, 4, 29), sys_setMy_date(2022, 8, 13), 0.95, "杭州", "294326", "江苏雨润食品产业集团有限公司", "A-02-5", "60Cnl雪碧");

	sys_testinput_setdata(16, 2002301, "60Onl可口可乐", 2.5, sys_setMy_date(2022, 4, 1), sys_setMy_date(2022, 8, 15), 0.95, "杭州", "294327", "杭州娃哈哈集团有限公司", "A-02-6", "60Onl可口可乐");

	sys_testinput_setdata(17, 2002301, "5o0al醒目[苹果]", 2.4, sys_setMy_date(2021, 1, 3), sys_setMy_date(2022, 9, 17), 0.95, "杭州", "294328", "杭州娃哈哈集团有限公司", "A-02-7", "5o0al醒目[苹果]");

	sys_testinput_setdata(18, 2002301, "可口可乐", 4.1, sys_setMy_date(2021, 1, 5), sys_setMy_date(2022, 9, 19), 0.9, "杭州", "294329", "杭州娃哈哈集团有限公司", "A-02-8", "可口可乐");

	sys_testinput_setdata(19, 2002301, "需碧", 4.1, sys_setMy_date(2021, 1, 7), sys_setMy_date(2022, 9, 21), 0.9, "杭州", "294330", "杭州娃哈哈集团有限公司", "B-01-2", "需碧");

	sys_testinput_setdata(20, 2002301, "330m1酷儿[橙汁】", 2.5, sys_setMy_date(2021, 1, 9), sys_setMy_date(2022, 9, 23), 0.9, "杭州", "294331", "杭州娃哈哈集团有限公司", "B-01-2", "330m1酷儿[橙汁】");

	sys_testinput_setdata(21, 2002301, "47Oal茶研工坊(清研》", 2.4, sys_setMy_date(2021, 1, 11), sys_setMy_date(2022, 9, 2), 0.9, "杭州", "294332", "杭州娃哈哈集团有限公司", "B-01-2", "47Oal茶研工坊(清研》");

	sys_testinput_setdata(22, 2002301, "18Onl霍巢冰爽柠檬茶", 2.4, sys_setMy_date(2021, 1, 13), sys_setMy_date(2022, 9, 4), 0.9, "杭州", "294333", "杭州娃哈哈集团有限公司", "B-01-2", "18Onl霍巢冰爽柠檬茶");

	sys_testinput_setdata(23, 2002301, "4150Al美汁源果粒橙", 2.8, sys_setMy_date(2021, 1, 15), sys_setMy_date(2022, 9, 15), 0.9, "杭州", "294334", "杭州娃哈哈集团有限公司", "B-01-2", "4150Al美汁源果粒橙");

	sys_testinput_setdata(24, 2002301, "美汁源果粒橙", 6.5, sys_setMy_date(2021, 1, 17), sys_setMy_date(2022, 9, 17), 0.9, "杭州", "294335", "杭州娃哈哈集团有限公司", "B-01-2", "美汁源果粒橙");

	sys_testinput_setdata(25, 2002301, "光明橙汁饮料", 6.5, sys_setMy_date(2021, 1, 19), sys_setMy_date(2022, 9, 13), 0.5, "上海", "294336", "杭州娃哈哈集团有限公司", "B-01-2", "光明橙汁饮料");

	sys_testinput_setdata(26, 2002301, "香派红糖姜茶", 9.5, sys_setMy_date(2021, 1, 21), sys_setMy_date(2022, 9, 15), 0.5, "杭州", "294337", "杭州娃哈哈集团有限公司", "B-01-2", "香派红糖姜茶");

	sys_testinput_setdata(27, 2002301, "杰巢咖啡(红装〉", 12.8, sys_setMy_date(2021, 1, 23), sys_setMy_date(2022, 9, 17), 0.5, "广东", "294338", "杭州娃哈哈集团有限公司", "B-01-2", "杰巢咖啡(红装〉");

	sys_testinput_setdata(28, 2002301, "雀巢咖啡1+2", 12.8, sys_setMy_date(2021, 1, 25), sys_setMy_date(2022, 9, 19), 1, "广东", "294339", "临沂新程金锣肉制品集团有限公司", "B-01-2", "雀巢咖啡1+2");

	sys_testinput_setdata(29, 2002301, "农夫果同100%阴萝卜", 3.5, sys_setMy_date(2021, 3, 27), sys_setMy_date(2022, 9, 21), 1, "杭州", "294340", "临沂新程金锣肉制品集团有限公司", "B-01-2", "农夫果同100%阴萝卜");

	sys_testinput_setdata(30, 2002301, "农夫果码10O%番茄味", 3.5, sys_setMy_date(2021, 3, 29), sys_setMy_date(2022, 9, 23), 1, "杭州", "294341", "临沂新程金锣肉制品集团有限公司", "B-01-2", "农夫果码10O%番茄味");

	sys_testinput_setdata(31, 2002301, "550ml农夫山泉天然水(普通型)", 1, sys_setMy_date(2021, 3, 1), sys_setMy_date(2022, 4, 2), 1, "杭州", "294342", "临沂新程金锣肉制品集团有限公司", "C-02-1", "550ml农夫山泉天然水(普通型)");

	sys_testinput_setdata(32, 2002301, "s8oAl农夫山泉天然水", 2, sys_setMy_date(2021, 3, 3), sys_setMy_date(2022, 4, 4), 1, "杭州", "294343", "临沂新程金锣肉制品集团有限公司", "C-02-2", "s8oAl农夫山泉天然水");

	sys_testinput_setdata(33, 2002301, "soo-l农夫果园30%懂胡味", 3.5, sys_setMy_date(2021, 7, 5), sys_setMy_date(2022, 4, 15), 1, "杭州", "294344", "临沂新程金锣肉制品集团有限公司", "C-02-3", "soo-l农夫果园30%懂胡味");

	sys_testinput_setdata(34, 2002301, "600.1农夫果园30%菠芒", 3.5, sys_setMy_date(2021, 7, 7), sys_setMy_date(2022, 4, 17), 1, "杭州", "294345", "吉林粮食集团有限公司", "C-02-4", "600.1农夫果园30%菠芒");

	sys_testinput_setdata(35, 2002301, "s80n1农夫果园30%番海味", 3.5, sys_setMy_date(2021, 7, 9), sys_setMy_date(2022, 4, 13), 1, "杭州", "294346", "吉林粮食集团有限公司", "C-02-5", "s80n1农夫果园30%番海味");

	sys_testinput_setdata(36, 2002301, "红牛饮料(促销)", 5.5, sys_setMy_date(2021, 7, 11), sys_setMy_date(2022, 4, 15), 1, "北前", "294347", "吉林粮食集团有限公司", "C-02-6", "红牛饮料(促销)");

	sys_testinput_setdata(37, 2002301, "80g香飘疯奶荼(吼味》", 2.6, sys_setMy_date(2021, 7, 13), sys_setMy_date(2022, 4, 17), 1, "湖州", "294348", "吉林粮食集团有限公司", "C-02-7", "80g香飘疯奶荼(吼味》");

	sys_testinput_setdata(38, 2002301, "8Og香飘飘奶茶（草莓）", 2.6, sys_setMy_date(2021, 7, 15), sys_setMy_date(2022, 4, 19), 1, "湖州", "294349", "吉林粮食集团有限公司", "C-02-8", "8Og香飘飘奶茶（草莓）");

	sys_testinput_setdata(39, 2002301, "80g香飘队奶荼(麦香)", 2.6, sys_setMy_date(2021, 7, 17), sys_setMy_date(2022, 4, 21), 1, "湖州", "294350", "吉林粮食集团有限公司", "C-02-9", "80g香飘队奶荼(麦香)");

	sys_testinput_setdata(40, 2002301, "8og否飘佩奶茶〔香擎）", 2.6, sys_setMy_date(2021, 12, 19), sys_setMy_date(2022, 4, 23), 1, "湖州", "294351", "吉林粮食集团有限公司", "C-02-10", "8og否飘佩奶茶〔香擎）");
}

///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

///
///

//程序入口，请接入主菜单
int main()
{
	sys_test_setdb();///先导入演示数据
	func_welcome_cd();///跳转到欢迎页，供用户选择角色
	return 0;
}





///
///




///管理员的菜单界面
int func_querysystem()
{
	try {
		int ch;
		system("cls");
		cout << "-----------------------------------------------------------------" << endl;
		cout << "超市管理系统 管理员" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "1.浏览商品信息" << endl;
		cout << "2.插入商品信息" << endl;
		cout << "3.删除商品信息" << endl;
		cout << "4.查找商品信息" << endl;
		cout << "5.商品信息修改" << endl;
		cout << "6.商品信息排序" << endl;
		cout << "7.折扣管理" << endl;
		cout << "8.供货商管理" << endl;
		cout << "9.顾客服务中心" << endl;
		cout << "10.退出管理员系统" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "请选择您要运行的功能选项:";
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
			func_ShowProductInfo();
			break;
		case 2:
			func_InsertProduct();
			break;
		case 3:
			func_DeleteProduct();
			break;
		case 4:
			func_SearchProduct();
			break;
		case 5:
			func_EditProduct();
			break;
		case 6:
			func_SortProduct();
			break;
		case 7:
			func_discount();
			break;
		case 8:
			func_producer();
			break;
		case 9:
			func_requset();
			break;
		case 10:
			func_welcome_cd();
			break;
		default:
			func_querysystem();
			return 0;
		}
	}catch(exception e){}
	func_querysystem();
	return 0;
}
///这个功能是显示商品信息的，并且只能显示商品信息
void func_ShowProductInfo() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品信息总览" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品成本   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "统计了共计 " << i - 1 << " 项商品." << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_querysystem();
}
///这个函数是插入商品信息的
void func_InsertProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "插入商品信息" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	ProductItem tpi;
	cout << "请输入商品编号:";
	cin >> tpi.ProductID;
	cout << "请输入商品名称:";
	cin >> tpi.ProductName;
	cout << "请输入商品价格:";
	cin >> tpi.ProductPrice;
	cout << "请输入商品成本:";
	cin >> tpi.ProductCost;
	cout << "请输入商品折扣(如果不打折请输入1,如95折输入0.95）:";
	cin >> tpi.ProductDiscount;
	cout << "请输入商品生产日期(格式如1970-01-01):";
	int dy, dm, dd;
	scanf_s("%d-%d-%d", &dy, &dm, &dd);
	tpi.ProductManufactureDate = sys_setMy_date(dy, dm, dd);
	cout << "请输入商品过期日期(格式如1970-01-01):";
	scanf_s("%d-%d-%d", &dy, &dm, &dd);
	tpi.ProductGuaranteePeriod = sys_setMy_date(dy, dm, dd);
	cout << "请输入商品生产地:";
	cin >> tpi.ProductOrigin;
	cout << "请输入商品生产批次:";
	cin >> tpi.ProductBatch;
	cout << "请输入商品所在货架号:";
	cin >> tpi.ProductShelf;
	cout << "请输入商品描述:";
	cin >> tpi.ProductDetails;
	for (int j = 1;; j++) {
		if (product[j].ProductID == 0) {
			product[j] = tpi;
			break;
		}
	}
	cout << "商品" << tpi.ProductName << "(" << tpi.ProductID << ")插入成功" << endl;
	cout << "继续插入商品请输入1按回车,返回上级菜单请输入任意字符按回车." << endl;
	char si;
	if (getchar() == '1') {
		func_InsertProduct();
	}
	else {
		func_querysystem();
	}
}
///这个函数是用来删除商品信息的
void func_DeleteProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "删除商品信息" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "请输入您要删除商品的序号(输入不存在的序号返回上级菜单):";
	int dindex = 0;
	cin >> dindex;
	try {
		if (product[dindex].ProductID == 0) {
			func_querysystem();
			return;
		}
	}
	catch (exception e) {
		func_querysystem();
		return;
	}
	ProductItem tpi = product[dindex];
	for (int j = dindex;; j++) {
		if (product[j].ProductID == 0 && product[j + 1].ProductID == 0) {
			break;
		}
		product[j] = product[j + 1];
	}
	cout << "商品" << tpi.ProductName << "(" << tpi.ProductID << ")删除成功" << endl;
	system("pause");
	cout << "继续删除商品请输入1按回车,返回上级菜单请输入任意字符按回车." << endl;
	char si;
	if (getchar() == '1') {
		func_DeleteProduct();
	}
	else {
		func_querysystem();
	}
}
///这个函数是商品检索的总菜单
void func_SearchProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查找指定名称商品" << endl;
	cout << "2.查找指定编号商品" << endl;
	cout << "3.查找指定折扣商品" << endl;
	cout << "4.查找价格区间商品" << endl;
	cout << "5.查找商品生产商所生产的商品" << endl;
	cout << "6.查找某一货架的所有商品" << endl;
	cout << "7.查找临期商品" << endl;
	cout << "8.查找过期商品" << endl;
	cout << "9.查找利润区间商品" << endl;
	cout << "10.查找成本区间商品" << endl;
	cout << "11.退出本菜单" << endl;
	cout << "请输入您需要操作的序号(输入不存在序号返回上级菜单):";
	int si;
	cin >> si;
	switch (si)
	{
	case 1:
		func_SearchProduct_byname();
		break;
	case 2:
		func_SearchProduct_byid();
		break;
	case 3:
		func_SearchProduct_bydiscount();
		break;
	case 4:
		func_SearchProduct_bypricesection();
		break;
	case 5:
		func_SearchProduct_byproducer();
		break;
	case 6:
		func_SearchProduct_byshelf();
		break;
	case 7:
		func_SearchProduct_bydate();
		break;
	case 8:
		func_SearchProduct_byoverdate();
		break;
	case 9:
		func_SearchProduct_byprofitsection();
		break;
	case 10:
		func_SearchProduct_bycostsection();
		break;
	case 11:
		func_welcome_cd();
		break;
	default:
		func_querysystem();
		break;
	}
}
///按照名称检索商品
void func_SearchProduct_byname() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定名称商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品名称:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductName != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照编号检索商品
void func_SearchProduct_byid() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定编号商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品编号:";
	int ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductID != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照折扣检索商品
void func_SearchProduct_bydiscount() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定折扣商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品折扣:";
	float ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductDiscount != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照价格区间段检索商品
void func_SearchProduct_bypricesection() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定价格区间商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品价格区间(如0-30表示查找价格在0-30元价格之间的商品):";
	float ti, ti1;
	scanf_s("%f-%f", &ti, &ti1);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合价格在" << ti << "到" << ti1 << "元之间.";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductPrice <= ti1 && product[i].ProductPrice >= ti) {}
		else {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照生产商检索商品
void func_SearchProduct_byproducer() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定生产商所生产商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品生产商:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductProducer != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照货架号检索商品
void func_SearchProduct_byshelf() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定货架的商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的货架号:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductShelf != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照离现在还有多少天到期检索商品
void func_SearchProduct_bydate() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找临期商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定多少天将要过期的商品:";
	int ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品生产日期   商品过期日期   剩余天数   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod) > ti && sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod) < 0) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << sys_My_date_tostring(product[i].ProductManufactureDate);
		cout << "   ";
		cout << sys_My_date_tostring(product[i].ProductGuaranteePeriod);
		cout << "   ";
		cout << sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod);
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///检索过期商品
void func_SearchProduct_byoverdate() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找过期商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品生产日期   商品过期日期   已过期天数   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod) >= 0) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << sys_My_date_tostring(product[i].ProductManufactureDate);
		cout << "   ";
		cout << sys_My_date_tostring(product[i].ProductGuaranteePeriod);
		cout << "   ";
		cout << abs(sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod));
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}


///按照利润区间段检索商品
void func_SearchProduct_byprofitsection() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定利润区间商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品利润区间(如0-30表示查找在0-30元利润之间的商品):";
	float ti, ti1;
	scanf_s("%f-%f", &ti, &ti1);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合利润在" << ti << "到" << ti1 << "元之间.";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品利润   商品成本   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductPrice*product[i].ProductDiscount - product[i].ProductCost <= ti1 && product[i].ProductPrice*product[i].ProductDiscount - product[i].ProductCost >= ti) {}
		else {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice*product[i].ProductDiscount - product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}
///按照成本区间段检索商品
void func_SearchProduct_bycostsection() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定成本区间商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的成本价格区间(如0-30表示查找成本在0-30元之间的商品):";
	float ti, ti1;
	scanf_s("%f-%f", &ti, &ti1);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合成本在" << ti << "到" << ti1 << "元之间.";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品利润   商品成本   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductCost <= ti1 && product[i].ProductCost >= ti) {}
		else {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice*product[i].ProductDiscount - product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SearchProduct();
}


///编辑商品信息
void func_EditProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "修改商品信息" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品成本   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "请输入您要修改商品的序号(输入不存在的序号返回上级菜单):";
	int dindex;
	cin >> dindex;
	try {
		if (product[i].ProductID == 0) {
			func_querysystem();
			return;
		}
	}
	catch (exception e) {
		func_querysystem();
		return;
	}
	cin >> dindex;
	cout << "您选中了商品" << product[dindex].ProductName << "(" << product[dindex].ProductID << "),并将要修改." << endl;
	ProductItem tpi;
	cout << "请输入商品编号:";
	cin >> tpi.ProductID;
	cout << "请输入商品名称:";
	cin >> tpi.ProductName;
	cout << "请输入商品价格:";
	cin >> tpi.ProductPrice;
	cout << "请输入商品成本:";
	cin >> tpi.ProductCost;
	cout << "请输入商品折扣(如果不打折请输入1,如95折输入0.95）:";
	cin >> tpi.ProductDiscount;
	cout << "请输入商品生产日期(格式如1970-01-01):";
	int dy, dm, dd;
	scanf_s("%d-%d-%d", &dy, &dm, &dd);
	tpi.ProductManufactureDate = sys_setMy_date(dy, dm, dd);
	cout << "请输入商品过期日期(格式如1970-01-01):";
	scanf_s("%d-%d-%d", &dy, &dm, &dd);
	tpi.ProductGuaranteePeriod = sys_setMy_date(dy, dm, dd);
	cout << "请输入商品生产地:";
	cin >> tpi.ProductOrigin;
	cout << "请输入商品生产批次:";
	cin >> tpi.ProductBatch;
	cout << "请输入商品所在货架号:";
	cin >> tpi.ProductShelf;
	cout << "请输入商品描述:";
	cin >> tpi.ProductDetails;
	product[dindex] = tpi;
	cout << "商品已更新为" << tpi.ProductName << "(" << tpi.ProductID << ")." << endl;
	cout << "继续修改商品请输入1按回车,返回上级菜单请输入任意字符按回车." << endl;
	char si;
	if (getchar() == '1') {
		func_EditProduct();
	}
	else {
		func_querysystem();
	}
}
///商品排序总菜单
void func_SortProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.按照商品序号(升序)排序" << endl;
	cout << "2.按照商品序号(降序)排序" << endl;
	cout << "3.按照价格[原价](升序)排序" << endl;
	cout << "4.按照价格[原价](降序)排序" << endl;
	cout << "5.按照价格[折扣后](升序)排序" << endl;
	cout << "6.按照价格[折扣后](降序)排序" << endl;
	cout << "7.按照折扣(升序)排序" << endl;
	cout << "8.按照折扣(降序)排序" << endl;
	cout << "9.按照商品利润(升序)排序" << endl;
	cout << "10.按照商品利润(降序)排序" << endl;
	cout << "请输入您需要操作的序号(输入不存在序号返回上级菜单):";
	int si;
	cin >> si;
	switch (si)
	{
	case 1:
		func_SortProduct_byid_up();
		break;
	case 2:
		func_SortProduct_byid_down();
		break;
	case 3:
		func_SortProduct_bypriceori_up();
		break;
	case 4:
		func_SortProduct_bypriceori_down();
		break;
	case 5:
		func_SortProduct_bypricemod_up();
		break;
	case 6:
		func_SortProduct_bypricemod_down();
		break;
	case 7:
		func_SortProduct_bydiscount_up();
		break;
	case 8:
		func_SortProduct_bydiscount_down();
		break;
	case 9:
		func_SortProduct_byprofit_up();
		break;
	case 10:
		func_SortProduct_byprofit_down();
		break;
	case 11:
		func_SortProduct_bycost_up();
		break;
	case 12:
		func_SortProduct_bycost_down();
		break;
	default:
		func_querysystem();
		break;
	}
}
///按照编号降序排序商品
void func_SortProduct_byid_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductID < product[j].ProductID) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品序号(降序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照编号升序排列商品
void func_SortProduct_byid_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductID > product[j].ProductID) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品序号(升序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照原价降序排列商品
void func_SortProduct_bypriceori_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductPrice < product[j].ProductPrice) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品价格[原价](降序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照原价升序排列商品
void func_SortProduct_bypriceori_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductPrice > product[j].ProductPrice) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品价格[原价](升序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照折扣后价格降序排列商品
void func_SortProduct_bypricemod_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductPrice * product[i].ProductDiscount < product[j].ProductID * product[j].ProductDiscount) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品价格[折扣后](降序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照折扣后价格升序排列商品
void func_SortProduct_bypricemod_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductPrice * product[i].ProductDiscount > product[j].ProductID * product[j].ProductDiscount) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品价格[折扣后](升序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照折扣力度降序排列
void func_SortProduct_bydiscount_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductDiscount < product[j].ProductDiscount) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品折扣(降序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照折扣力度升序排列
void func_SortProduct_bydiscount_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductDiscount > product[j].ProductDiscount) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品折扣(升序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}

void func_SortProduct_byprofit_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductDiscount*product[i].ProductPrice - product[i].ProductCost < product[j].ProductDiscount*product[j].ProductPrice - product[j].ProductCost) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品利润排序[降序] 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品成本   商品利润   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount*product[i].ProductPrice - product[i].ProductCost;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}


void func_SortProduct_byprofit_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductDiscount*product[i].ProductPrice - product[i].ProductCost > product[j].ProductDiscount*product[j].ProductPrice - product[j].ProductCost) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品利润排序[升序] 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品成本   商品利润   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount*product[i].ProductPrice - product[i].ProductCost;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}


///按照成本降序排序商品
void func_SortProduct_bycost_down() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductCost < product[j].ProductCost) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品序号(降序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品成本   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}
///按照成本升序排列商品
void func_SortProduct_bycost_up() {
	system("cls");
	int index = 0;
	for (index = 1;; index++) {
		if (product[index].ProductID == 0) {
			break;
		}
	}
	index--;
	for (int i = 1; i <= index; i++) {
		for (int j = i; j <= index; j++) {
			if (product[i].ProductCost > product[j].ProductCost) {
				ProductItem ti = product[i];
				product[i] = product[j];
				product[j] = ti;
			}
		}
	}

	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品排序 按照商品序号(升序)排序 已完成" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "排序结果" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品成本   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductCost;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_SortProduct();
}


///
///

///© 2022 Sonaradar Electronic Inc.All rights reserved. get more at www.sonaradar.top.
///折扣系统部分
void func_discount() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "折扣管理" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   折扣后价格   商品折扣" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "请输入需要操作的商品的序号(取消请输入0):";
	int selectno;
	cin >> selectno;
	if (selectno <= i && selectno > 0) {
		sys_discount_1(selectno);
		return;
	}
	system("pause");
	func_querysystem();
}
///折扣修改
void sys_discount_1(int n) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 折扣修改" << endl;///自行修改
	cout << "当前选中商品 " << product[n].ProductName << "(" << product[n].ProductID << ")" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "" << endl;
	cout << "1.修改折扣" << endl;
	cout << "2.一键设置5折" << endl;
	cout << "3.一键设置9折" << endl;
	cout << "4.一键设置95折" << endl;
	cout << "5.恢复商品原价" << endl;
	cout << "输入其他数值返回主页面" << endl;
	cout << "" << endl;
	cout << "请输入需要操作的商品的编号(取消请输入0):";
	int selectno;
	cin >> selectno;
	cout << "" << endl;
	float dis;
	switch (selectno)
	{
	case 1:
		cout << "请输入折扣:";
		cin >> dis;
		product[n].ProductDiscount = dis;
		cout << "商品 " << product[n].ProductName << "(" << product[n].ProductID << ") 已设置折扣为" << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
		break;
	case 2:
		dis = 0.5;
		product[n].ProductDiscount = dis;
		cout << "商品 " << product[n].ProductName << "(" << product[n].ProductID << ") 已设置折扣为" << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
		break;
	case 3:
		dis = 0.9;
		product[n].ProductDiscount = dis;
		cout << "商品 " << product[n].ProductName << "(" << product[n].ProductID << ") 已设置折扣为" << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
		break;
	case 4:
		dis = 0.95;
		product[n].ProductDiscount = dis;
		cout << "商品 " << product[n].ProductName << "(" << product[n].ProductID << ") 已设置折扣为" << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
		break;
	case 5:
		dis = 1;
		product[n].ProductDiscount = dis;
		cout << "商品 " << product[n].ProductName << "(" << product[n].ProductID << ") 已恢复原价" << endl;
		break;
	default:
		break;
	}
	system("pause");
	func_querysystem();
}
///生产商管理
void func_producer() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "供货商信息" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductOrigin;
		cout << "   ";
		cout << product[i].ProductBatch;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "功能选项:" << endl;
	cout << "1.查询指定供货商所有商品" << endl;
	cout << "2.查询指定货架号所有商品" << endl;
	cout << "3.查询指定原产地所有商品" << endl;
	cout << "请输入需要操作的序号(返回请输入输入0):";
	int s;
	cin >> s;
	cout << "" << endl;
	string target;
	switch (s)
	{
	case 1:
		cout << "请输入指定的供货商:";
		cin >> target;
		system("cls");
		cout << "-----------------------------------------------------------------" << endl;
		cout << "供货商 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductProducer != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	case 2:
		cout << "请输入指定的货架号:";
		cin >> target;
		system("cls");
		cout << "-----------------------------------------------------------------" << endl;
		cout << "货架号 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductShelf != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	case 3:
		cout << "请输入指定的原产地:";
		cin >> target;
		system("cls");
		cout << "-原产地 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductOrigin != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	default:
		break;
	}
	system("pause");
	func_querysystem();
}

///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.


///
///


///客户的菜单
void func_cus_cd() {
	int ch;
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 客户" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.浏览商品信息" << endl;
	cout << "2.查找商品信息" << endl;
	cout << "3.折扣查看" << endl;
	cout << "4.供货商查看" << endl;
	cout << "5.多功能查找商品" << endl;
	cout << "6.顾客服务中心" << endl;
	cout << "7.退出本菜单" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请选择您要运行的功能选项:";
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 1:
		func_cus_ShowProductInfo();
		break;
	case 2:
		func_cus_SearchProduct();
		break;
	case 3:
		func_cus_discount();
		break;
	case 4:
		func_cus_producer();
		break;
	case 5:
		func_cus_SearchProduct();
		break;
	case 6:
		func_cus_requset();
		break;
	case 7:
		func_welcome_cd();
		break;
	default:
		func_cus_cd();
		return;
	}
}
///顾客查询商品入口
///过期商品直接不显示，管理员端可以显示过期的产品
void func_cus_ShowProductInfo() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "商品信息总览" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (sys_getday(sys_My_date_getcurrentdate(), product[i].ProductGuaranteePeriod) < 0) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "共有 " << i - 1 << " 项商品在售." << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_cd();
}
///折扣系统部分
void func_cus_discount() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "折扣管理" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   折扣后价格   商品折扣" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车返回上级菜单";
	system("pause");
	func_cus_cd();
}
///溯源\商品原产地管理
void func_cus_producer() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "供货商信息" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductOrigin;
		cout << "   ";
		cout << product[i].ProductBatch;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "功能选项:" << endl;
	cout << "1.查询指定供货商所有商品" << endl;
	cout << "2.查询指定货架号所有商品" << endl;
	cout << "3.查询指定原产地所有商品" << endl;
	cout << "请输入需要操作的序号(返回请输入输入0):";
	int s;
	cin >> s;
	cout << "" << endl;
	string target;
	switch (s)
	{
	case 1:
		cout << "请输入指定的供货商:";
		cin >> target;
		system("cls");
		cout << "-----------------------------------------------------------------" << endl;
		cout << "供货商 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductProducer != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	case 2:
		cout << "请输入指定的货架号:";
		cin >> target;
		system("cls");
		cout << "-----------------------------------------------------------------" << endl;
		cout << "货架号 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductShelf != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	case 3:
		cout << "请输入指定的原产地:";
		cin >> target;
		system("cls");
		cout << "-原产地 " << target << " 的所有商品" << endl;///自行修改
		cout << "-----------------------------------------------------------------" << endl;
		cout << "序号   商品名称   商品编号   供货商   商品原产地   商品批次   商品货架号   商品描述" << endl;
		cout << "" << endl;
		for (i = 1;; i++) {
			if (product[i].ProductID == 0) {
				break;
			}
			if (product[i].ProductOrigin != target) {
				continue;
			}
			cout << i;
			cout << "   ";
			cout << product[i].ProductName;
			cout << "   ";
			cout << product[i].ProductID;
			cout << "   ";
			cout << product[i].ProductProducer;
			cout << "   ";
			cout << product[i].ProductOrigin;
			cout << "   ";
			cout << product[i].ProductBatch;
			cout << "   ";
			cout << product[i].ProductShelf;
			cout << "   ";
			cout << product[i].ProductDetails;
			cout << "   " << endl;
		}
		break;
	default:
		break;
	}
	system("pause");
	func_cus_cd();
}

///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

///
///


///这个函数是商品检索的总菜单，给顾客用的，和管理员的有改动
void func_cus_SearchProduct() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查找指定名称商品" << endl;
	cout << "2.查找指定编号商品" << endl;
	cout << "3.查找指定折扣商品" << endl;
	cout << "4.查找价格区间商品" << endl;
	cout << "5.查找商品生产商所生产的商品" << endl;
	cout << "6.查找某一货架的所有商品" << endl;
	cout << "7.退出本菜单" << endl;
	cout << "请输入您需要操作的序号(输入不存在序号返回上级菜单):";
	int si;
	cin >> si;
	switch (si)
	{
	case 1:
		func_SearchProduct_byname();
		break;
	case 2:
		func_SearchProduct_byid();
		break;
	case 3:
		func_SearchProduct_bydiscount();
		break;
	case 4:
		func_SearchProduct_bypricesection();
		break;
	case 5:
		func_SearchProduct_byproducer();
		break;
	case 6:
		func_SearchProduct_byshelf();
		break;
	case 7:
		func_cus_cd();
		break;
	default:
		func_cus_SearchProduct();
		break;
	}
}
///按照名称检索商品
void func_cus_SearchProduct_byname() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定名称商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品名称:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductName != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}
///按照编号检索商品
void func_cus_SearchProduct_byid() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定编号商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品编号:";
	int ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductID != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}




///按照折扣检索商品
void func_cus_SearchProduct_bydiscount() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定折扣商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品折扣:";
	float ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductDiscount != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}



///按照价格区间段检索商品
void func_cus_SearchProduct_bypricesection() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定价格区间商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品价格区间(如0-30表示查找价格在0-30元价格之间的商品):";
	float ti, ti1;
	scanf_s("%f-%f", &ti, &ti1);
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合价格在" << ti << "到" << ti1 << "元之间.";
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductPrice <= ti1 && product[i].ProductPrice >= ti) {}
		else {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}




///按照生产商检索商品
void func_cus_SearchProduct_byproducer() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定生产商所生产商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的商品生产商:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductProducer != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}



///按照货架号检索商品
void func_cus_SearchProduct_byshelf() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "分类查找商品   查找指定货架的商品" << endl;///自行修改
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入您指定的货架号:";
	string ti;
	cin >> ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "查找到以下项目符合条件:" << ti;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "序号   商品名称   商品编号   商品价格   商品售价(折扣后价格)   商品折扣   商品生产商   所在货架   商品描述" << endl;
	cout << "" << endl;
	int i;
	for (i = 1;; i++) {
		if (product[i].ProductID == 0) {
			break;
		}
		if (product[i].ProductShelf != ti) {
			continue;
		}
		cout << i;
		cout << "   ";
		cout << product[i].ProductName;
		cout << "   ";
		cout << product[i].ProductID;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductPrice * product[i].ProductDiscount;
		cout << "   ";
		cout << setiosflags(ios::fixed) << setprecision(2) << product[i].ProductDiscount;
		cout << "   ";
		cout << product[i].ProductProducer;
		cout << "   ";
		cout << product[i].ProductShelf;
		cout << "   ";
		cout << product[i].ProductDetails;
		cout << "   " << endl;
	}
	cout << "" << endl;
	cout << "按回车键返回上级菜单" << endl;
	system("pause");
	func_cus_SearchProduct();
}


///
///

///角色选择 主菜单
void  func_welcome_cd() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统" << endl;///自行修改
	cout << "欢迎您,今天是" << sys_My_date_tostring(sys_My_date_getcurrentdate()) << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.我是顾客" << endl;
	cout << "2.我是工作人员" << endl;
	cout << "请您选择您的身份:";
	int indexs;
	cin >> indexs;
	if (indexs == 2) {
		func_login();
		return;
	}
	func_cus_cd();
	return;
}




///登录
bool func_login() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "                      超市管理系统 认证" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请输入管理员秘钥:";
	string key;
	cin >> key;
	if (key == pwd) {
		cout << "登录成功,欢迎回来." << endl;
		system("pause");
		func_querysystem();
		return true;
	}
	cout << "秘钥错误,是否重新尝试?" << endl;
	cout << "输入y重新尝试,只按回车退出登录." << endl;
	string cfm;
	cin >> cfm;
	if (cfm == "y" || cfm == "Y") {
		return func_login();
	}
	func_welcome_cd();
	return false;
}

///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.

////
////


void func_cus_requset() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.申请服务/投诉反馈" << endl;
	cout << "2.查询工单状态/反馈" << endl;
	cout << "3.返回上级菜单" << endl;
	cout << "请输入您需要的服务的编号:";
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_cus_request_create();
		break;
	case 2:
		func_cus_request_findrequest_byid();
		break;
	case 3:
		func_cus_cd();
		break;
	default:
		func_cus_requset();
		break;
	}
}
void func_cus_request_create() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "请问您要反馈/投诉/申请什么问题?" << endl;
	cout << "1.服务投诉" << endl;
	cout << "2.价格投诉" << endl;
	cout << "3.退换货申请" << endl;
	cout << "4.商品咨询" << endl;
	cout << "5.送货上门申请" << endl;
	cout << "6.申请开票" << endl;
	cout << "7.大客户购物卡办理" << endl;
	cout << "8.其他申请/反馈" << endl;
	cout << "9.返回上级菜单" << endl;
	cout << "请输入您需要的服务的编号:";
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_cus_request_create_1();
		break;
	case 2:
		func_cus_request_create_2();
		break;
	case 3:
		func_cus_request_create_3();
		break;
	case 4:
		func_cus_request_create_4();
		break;
	case 5:
		func_cus_request_create_5();
		break;
	case 6:
		func_cus_request_create_6();
		break;
	case 7:
		func_cus_request_create_7();
		break;
	case 8:
		func_cus_request_create_8();
		break;
	case 9:
		func_cus_requset();
		break;
	default:
		func_cus_request_create();
		break;
	}
}
void func_cus_request_create_1() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 1;
	cout << "请输入您的需要服务投诉的内容:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_2() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 2;
	cout << "请输入您的需要价格投诉的内容:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}

void func_cus_request_create_3() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 3;
	cout << "请输入您的退换货申请:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_4() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 4;
	cout << "请输入您的需要咨询的商品内容:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_5() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 5;
	cout << "请输入您的送货上门申请:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_6() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 6;
	cout << "请输入您的开票申请:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_7() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 7;
	cout << "请输入您的购物卡办理需求:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_request_create_8() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	RequsetForm trf;
	trf.requestClass = 8;
	cout << "请输入您的反馈:";
	cin >> trf.request;
	cout << "为了保证我们能够给您处理结果,请您填写您的联系方式." << endl;
	cout << "您的姓名:";
	cin >> trf.name;
	cout << "您的联系方式:";
	cin >> trf.contractway;
	int i;
	for (i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
	}
	trf.id = (100000000 + i);
	request[i] = trf;
	cout << "您的反馈/请求提交成功，工单号:" << trf.id << ",请牢记您的工单号,以便后续查询." << endl;;
	system("pause");
	func_cus_requset();
}
void func_cus_requsetview(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单反馈" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	if (request[id - 100000000].isResponded) {
		cout << "处理状态:" << "已处理" << endl;
		if (request[id - 100000000].isAgree) {
			cout << "处理意见:" << "同意" << endl;
		}
		else {
			cout << "处理意见:" << "拒绝" << endl;
		}
		cout << "处理意见详情:" << request[id - 100000000].result << endl;
		cout << "处理人:" << request[id - 100000000].responder << endl;
	}
	else {
		cout << "处理状态:" << "未处理" << endl;
	}
	cout << "如果您对处理意见有任何异议或过长时间未处理，我们建议您重新填写工单." << endl;
	system("pause");
	func_cus_requset();
}

void func_cus_request_findrequest_byid() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单查询" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	int idc;
	cin >> idc;

	try {
		if (request[idc - 100000000].requestClass == 0) {
			cout << "该工单不存在XD." << endl;
			system("pause");
			func_cus_requset();
			return;
		}
		else {
			func_cus_requsetview(idc);
		}
	}
	catch (exception ws) {
		cout << "该工单不存在XD." << endl;
		system("pause");
		func_cus_requset();
	}
}
///管理员部分
void func_requset() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 顾客意见申请处理中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查看所有工单" << endl;
	cout << "2.查看现行已解决工单" << endl;
	cout << "3.查看现行未解决工单" << endl;
	cout << "4.返回上级菜单" << endl;
	cout << "请输入您需要的服务的编号:";
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_requset_manager_all();
		break;
	case 2:
		func_requset_manager_fininshed();
		break;
	case 3:
		func_requset_manager_unfinished();
		break;
	case 4:
		func_querysystem();
		break;
	default:
		func_requset();
		break;
	}
}
void func_requset_manager_all() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 顾客意见申请处理中心" << endl;
	cout << "工单管理[全部]" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号   工单类型   工单申请人   工单联系方式   工单现行状态" << endl;

	for (int i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
		cout << request[i].id << "   ";
		switch (request[i].requestClass)
		{

		case 1:
			cout << "服务投诉" << "   ";
			break;
		case 2:
			cout << "价格投诉" << "   ";
			break;
		case 3:
			cout << "退换货申请" << "   ";
			break;
		case 4:
			cout << "商品咨询" << "   ";
			break;
		case 5:
			cout << "送货上门申请" << "   ";
			break;
		case 6:
			cout << "开票申请" << "   ";
			break;
		case 7:
			cout << "大客户购物卡办理" << "   ";
			break;
		case 8:
			cout << "其他类别" << "   ";
			break;
		default:
			cout << "未知类别" << "   ";
			break;
		}
		cout << request[i].name << "   ";
		cout << request[i].contractway << "   ";
		if (request[i].isResponded) {
			cout << "已处理" << "   ";
		}
		else {
			cout << "未处理" << "   ";
		}
		cout << "\n";

	}
	cout << "请选择您需要编辑/查看的工单(输入不存在工单返回上级菜单):";
	int indexc;
	cin >> indexc;
	try {
		if (request[indexc - 100000000].requestClass == 0) {
			cout << "工单未找到，返回上级菜单" << endl;
			system("pause");
			func_requset();
			return;
		}
	}
	catch (exception se) {
		cout << "工单未找到，返回上级菜单" << endl;
		system("pause");
		func_requset();
		return;
	}
	func_request_viewer_all(indexc);
}
void func_request_viewer_all(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查询工单内容" << endl;
	cout << "2.回复工单" << endl;
	cout << "3.返回上级菜单" << endl;
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_requsetview_all(id);
		break;
	case 2:
		func_requsetview_reply_all(id);
		break;
	default:
		func_requset_manager_all();
		break;
	}
}
void func_requsetview_all(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单反馈" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	if (request[id - 100000000].isResponded) {
		cout << "处理状态:" << "已处理" << endl;
		if (request[id - 100000000].isAgree) {
			cout << "处理意见:" << "同意" << endl;
		}
		else {
			cout << "处理意见:" << "拒绝" << endl;
		}
		cout << "处理意见详情:" << request[id - 100000000].result << endl;
		cout << "处理人:" << request[id - 100000000].responder << endl;
	}
	else {
		cout << "处理状态:" << "未处理" << endl;
	}
	system("pause");
	func_requset_manager_all();
}
void func_requsetview_reply_all(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单回复" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	cout << "商家意见:";
	cin >> request[id - 100000000].result;
	cout << "状态设置(0-拒绝,1-同意):";
	cin >> request[id - 100000000].isAgree;
	request[id - 100000000].isResponded = true;
	cout << "工单回复完毕" << endl;
	system("pause");
	func_requset_manager_all();
}
void func_requset_manager_fininshed() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 顾客意见申请处理中心" << endl;
	cout << "工单管理[已办结]" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号   工单类型   工单申请人   工单联系方式   工单现行状态" << endl;

	for (int i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
		cout << request[i].id << "   ";
		switch (request[i].requestClass)
		{

		case 1:
			cout << "服务投诉" << "   ";
			break;
		case 2:
			cout << "价格投诉" << "   ";
			break;
		case 3:
			cout << "退换货申请" << "   ";
			break;
		case 4:
			cout << "商品咨询" << "   ";
			break;
		case 5:
			cout << "送货上门申请" << "   ";
			break;
		case 6:
			cout << "开票申请" << "   ";
			break;
		case 7:
			cout << "大客户购物卡办理" << "   ";
			break;
		case 8:
			cout << "其他类别" << "   ";
			break;
		default:
			cout << "未知类别" << "   ";
			break;
		}
		cout << request[i].name << "   ";
		cout << request[i].contractway << "   ";
		if (request[i].isResponded) {
			cout << "已处理" << "   ";
		}
		else {
			cout << "未处理" << "   ";
		}
		cout << "\n";
	}
	cout << "请选择您需要编辑/查看的工单(输入不存在工单返回上级菜单):";
	int indexc;
	cin >> indexc;
	try {
		if (request[indexc - 100000000].requestClass == 0) {
			cout << "工单未找到，返回上级菜单" << endl;
			system("pause");
			func_requset();
			return;
		}
	}
	catch (exception se) {
		cout << "工单未找到，返回上级菜单" << endl;
		system("pause");
		func_requset();
		return;
	}
	func_request_viewer_fininshed(indexc);
}
void func_request_viewer_fininshed(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查询工单内容" << endl;
	cout << "2.返回上级菜单" << endl;
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_requsetview_fininshed(id);
		break;
	default:
		func_requset_manager_fininshed();
		break;
	}
}
void func_requsetview_fininshed(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单反馈" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	if (request[id - 100000000].isResponded) {
		cout << "处理状态:" << "已处理" << endl;
		if (request[id - 100000000].isAgree) {
			cout << "处理意见:" << "同意" << endl;
		}
		else {
			cout << "处理意见:" << "拒绝" << endl;
		}
		cout << "处理意见详情:" << request[id - 100000000].result << endl;
		cout << "处理人:" << request[id - 100000000].responder << endl;
	}
	else {
		cout << "处理状态:" << "未处理" << endl;
	}
	system("pause");
	func_requset_manager_fininshed();
}
void func_requset_manager_unfinished() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 顾客意见申请处理中心" << endl;
	cout << "工单管理[全部]" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号   工单类型   工单申请人   工单联系方式   工单现行状态" << endl;

	for (int i = 1;; i++) {
		if (request[i].requestClass == 0) {
			break;
		}
		cout << request[i].id << "   ";
		switch (request[i].requestClass)
		{

		case 1:
			cout << "服务投诉" << "   ";
			break;
		case 2:
			cout << "价格投诉" << "   ";
			break;
		case 3:
			cout << "退换货申请" << "   ";
			break;
		case 4:
			cout << "商品咨询" << "   ";
			break;
		case 5:
			cout << "送货上门申请" << "   ";
			break;
		case 6:
			cout << "开票申请" << "   ";
			break;
		case 7:
			cout << "大客户购物卡办理" << "   ";
			break;
		case 8:
			cout << "其他类别" << "   ";
			break;
		default:
			cout << "未知类别" << "   ";
			break;
		}
		cout << request[i].name << "   ";
		cout << request[i].contractway << "   ";
		if (request[i].isResponded) {
			cout << "已处理" << "   ";
		}
		else {
			cout << "未处理" << "   ";
		}
		cout << "\n";
	}
	cout << "请选择您需要编辑/查看的工单(输入不存在工单返回上级菜单):";
	int indexc;
	cin >> indexc;
	try {
		if (request[indexc - 100000000].requestClass == 0) {
			cout << "工单未找到，返回上级菜单" << endl;
			system("pause");
			func_requset();
			return;
		}
	}
	catch (exception se) {
		cout << "工单未找到，返回上级菜单" << endl;
		system("pause");
		func_requset();
		return;
	}
	func_request_viewer_unfinished(indexc);
}
void func_request_viewer_unfinished(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1.查询工单内容" << endl;
	cout << "2.回复工单" << endl;
	cout << "3.返回上级菜单" << endl;
	int indexc;
	cin >> indexc;
	switch (indexc)
	{
	case 1:
		func_requsetview_unfinished(id);
		break;
	case 2:
		func_requsetview_reply_unfinished(id);
		break;
	default:
		func_requset_manager_unfinished();
		break;
	}
}
void func_requsetview_unfinished(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单反馈" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	if (request[id - 100000000].isResponded) {
		cout << "处理状态:" << "已处理" << endl;
		if (request[id - 100000000].isAgree) {
			cout << "处理意见:" << "同意" << endl;
		}
		else {
			cout << "处理意见:" << "拒绝" << endl;
		}
		cout << "处理意见详情:" << request[id - 100000000].result << endl;
		cout << "处理人:" << request[id - 100000000].responder << endl;
	}
	else {
		cout << "处理状态:" << "未处理" << endl;
	}
	system("pause");
	func_requset_manager_unfinished();
}
void func_requsetview_reply_unfinished(int id) {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "超市管理系统 服务中心" << endl;
	cout << "工单回复" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "工单编号:" << id << endl;
	switch (request[id - 100000000].requestClass)
	{

	case 1:
		cout << "工单类型:" << "服务投诉" << endl;
		break;
	case 2:
		cout << "工单类型:" << "价格投诉" << endl;
		break;
	case 3:
		cout << "工单类型:" << "退换货申请" << endl;
		break;
	case 4:
		cout << "工单类型:" << "商品咨询" << endl;
		break;
	case 5:
		cout << "工单类型:" << "送货上门申请" << endl;
		break;
	case 6:
		cout << "工单类型:" << "开票申请" << endl;
		break;
	case 7:
		cout << "工单类型:" << "大客户购物卡办理" << endl;
		break;
	case 8:
		cout << "工单类型:" << "其他类别" << endl;
		break;
	default:
		cout << "工单类型:" << "未知类别" << endl;
		break;
	}
	cout << "客户申请:" << request[id - 100000000].request << endl;
	cout << "商家意见:";
	cin >> request[id - 100000000].result;
	cout << "状态设置(0-拒绝,1-同意):";
	cin >> request[id - 100000000].isAgree;
	request[id - 100000000].isResponded = true;
	cout << "工单回复完毕" << endl;
	system("pause");
	func_requset_manager_unfinished();
}
///©2022-2021 SONARADAR.TOP.ALL RIGHTS RESERVED.
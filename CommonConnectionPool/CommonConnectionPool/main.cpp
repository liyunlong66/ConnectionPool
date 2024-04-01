#include "Connection.h"
#include "CommonConnectionPool.h"
#include <iostream>
int main() {

	clock_t begin = clock();
	ConnectionPool* cp = ConnectionPool::getConnectionPool();
	for (int i = 0; i < 1000;++i) {
	/*	Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhangsan", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123456", "test");
		conn.update(sql);*/
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhangsan", 20, "male");
		shared_ptr<Connection> conn = cp->getConnection();
		conn->update(sql);
	}
	clock_t end = clock();
	cout << (end - begin) << "ms" << endl;
	return 0;
}
#include "gtest/gtest.h"

#include "PRCM.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//void sender(bool& exit,int& received_message_counter );
//void receiver(bool& exit, int& received_message_counter);


struct ProcessCommunicator_Tests : testing::Test
{
	int data_to_send = 11;
	int received_data = 0;
	bool _exit = false;
	int received_message_counter = 0;
	void reset_data()
	{
		data_to_send = 0;
		received_data = 0;
		received_message_counter = 0;
	}

};

template <class T>
void sender(bool& exit, T& to_send)
{
	pr_cmm::ProcessCommunicator::send_message<T>(to_send, "msg");
}

template <class T>
void receiver(bool& exit, T& to_receive)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	pr_cmm::ProcessCommunicator::get_message<T>(to_receive, "msg");
}

template <class T>
void random_sender(bool& exit, T& to_send)
{
	while (!exit)
	{
		to_send = rand() % 100;
		pr_cmm::ProcessCommunicator::send_message<T>(to_send, "supername");
	}
}


template <typename T>
void message_per_second(bool& exit, T& to_send, T& to_receive, int& received_message_counter)
{

	while (!exit)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		pr_cmm::ProcessCommunicator::get_message<T>(to_receive, "supername");
		if (to_send == to_receive)
			received_message_counter++;

	}
}





TEST_F(ProcessCommunicator_Tests, SameThreadTest) {
	// receiving data in same thread
	data_to_send = 100;
	pr_cmm::ProcessCommunicator::send_message(data_to_send, "msg");
	pr_cmm::ProcessCommunicator::get_message(received_data, "msg");
	EXPECT_EQ(data_to_send, received_data);
	data_to_send = 50;
	pr_cmm::ProcessCommunicator::send_message(data_to_send, "msg");
	pr_cmm::ProcessCommunicator::get_message(received_data, "msg");
	EXPECT_EQ(data_to_send, received_data);
	data_to_send = 5;
	pr_cmm::ProcessCommunicator::send_message(data_to_send, "msg");
	pr_cmm::ProcessCommunicator::get_message(received_data, "msg");
	EXPECT_EQ(data_to_send, received_data);
	EXPECT_TRUE(true);
}

TEST_F(ProcessCommunicator_Tests, DIffThreads) {
	// receiving data between threads
	ProcessCommunicator_Tests::data_to_send = 5;
	ProcessCommunicator_Tests::received_data = 0;
	std::thread th1(sender<int>, std::ref(_exit), std::ref(ProcessCommunicator_Tests::data_to_send));
	std::thread th2(receiver<int>, std::ref(_exit), std::ref(ProcessCommunicator_Tests::received_data));
	th1.detach();
	th2.detach();
	std::this_thread::sleep_for(std::chrono::milliseconds(2)); //2ms minimum
	ProcessCommunicator_Tests::_exit = true;
	EXPECT_EQ(data_to_send, received_data);

}


TEST_F(ProcessCommunicator_Tests, MessagePerSecond) {
	// receiving int messages per second  between threads
	srand(time(NULL));

	ProcessCommunicator_Tests::data_to_send = 0;
	ProcessCommunicator_Tests::received_data = 0;
	ProcessCommunicator_Tests::received_message_counter = 0;

	std::thread th1(random_sender<int>, std::ref(_exit),
		std::ref(ProcessCommunicator_Tests::data_to_send));
	std::thread th2(message_per_second<int>, std::ref(_exit),
		std::ref(ProcessCommunicator_Tests::data_to_send),
		std::ref(ProcessCommunicator_Tests::received_data),
		std::ref(received_message_counter));
	th1.detach();
	th2.detach();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	ProcessCommunicator_Tests::_exit = true;
	std::cout << "Messages was received: " << received_message_counter;
	EXPECT_EQ(received_message_counter, 100);

}

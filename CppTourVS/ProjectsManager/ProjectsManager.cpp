#include "ProjectsManager.h"

namespace project_manager {

	ProjectsManager::ProjectsManager(int &argc, char* argv[])
	{
		this->argc = &argc;
		this->argv = argv;
	}

	// Multithreading/ProcessCommunicator

	void ProjectsManager::process_communicator()
	{
		bool _exit = false;
		pr_cmm::ProcessCommunicator prc;
		std::thread th1(pr_cmm::sprocess_1, std::ref(_exit));
		std::thread th2(pr_cmm::sprocess_2, std::ref(_exit));
		th1.detach();
		th2.detach();

		std::cin.get();
		_exit = true;

	}

	void ProjectsManager::process_communicator_tests()
	{
		{
			testing::InitGoogleTest(this->argc, this->argv);
			testing::GTEST_FLAG(filter) = "ProcessCommunicator_Tests*";
			RUN_ALL_TESTS();
		}
	}

	// _DataStructures//MyList 
	void ProjectsManager::run_my_list()
	{
		//std::cout << "adsfgsgd";
		//my_list::sa();
	
		my_list::List<int> df;
		df.push_back(10);
		df.push_back(20);
		df.push_back(30);
		df.push_back(40);
		df.push_back(50);
		df.push_back(60);

		for(int i = 0; i < df.get_size(); i++)
		{
			std::cout << df[i] << "\n";
		}
		df.remove(2);
		std::cout << "result:" << std::endl;
		for (int i = 0; i < df.get_size(); i++)
		{
			std::cout << df[i] << "\n";
		}
		//std::cout << df[0] <<"\n";
		//std::cout << df[1] << "\n";
		//std::cout << df[2] << "\n";
	}

} // namespace project_manager
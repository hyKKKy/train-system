#include <iostream>
#include <vector>

class Train
{
public:
	Train()
	{
		number = "empty";
		arrival_time = "empty";
		destination = "empty";
	}
	Train(const std::string& number, const std::string& arrival_time, const std::string& destination)
		: number(number), arrival_time(arrival_time), destination(destination) {}

	~Train() {};

	void printAll() const {
		std::cout << "Train's number: " << number << std::endl;
		std::cout << "Arrival time: " << arrival_time << std::endl;
		std::cout << "Destination: " << destination << std::endl;
	}

	void addTrainNumber(const std::string& number) {
		this->number = number;
		std::cout << "You've added number!" << std::endl;
	}

	void addArrivalTime(const std::string& arrival_time) {
		this->arrival_time = arrival_time;
		std::cout << "You've added arrival time!" << std::endl;
	}

	void addDestination(const std::string& destination) {
		this->destination = destination;
		std::cout << "You've added destination!" << std::endl;
	}

	std::string GetNumber() {
		return number;
	}

private:
	std::string number;
	std::string arrival_time;
	std::string destination;

};


class TrainSystem
{
public:
	
	void AddTrain(const Train& train) {
		this->trains.push_back(train);
	}

	void RemoveTrain() {
		if (this->trains.empty()) {
			std::cout << "Nothing to remove!" << std::endl;
		}
		else
		{
			trains.pop_back();
		}
	}

	void Print() {
		if (!trains.empty())
		{
			for (int i = 0; i < trains.size(); i++)
			{
				trains[i].printAll();
				std::cout << "---------------------------" << std::endl;
			}
		}
		else
		{
			std::cout << "Train system is empty!" << std::endl;
		}
	}

	void findByNumber(const std::string& number) {
		bool flag = false;
		if (!trains.empty())
		{
			for (int i = 0; i < trains.size(); i++)
			{
				if (trains[i].GetNumber() == number) {
					std::cout << "Train is found!" << std::endl;
					std::cout << "---------------->" << std::endl;
					trains[i].printAll();
					flag = true;
					break;
				}
			}
			if (!flag) {
				std::cout << "Nothing has found!" << std::endl;
			}
		}
		else
		{
			std::cout << "System is empty!" << std::endl;
		}
	}

	~TrainSystem() {};

private:
	std::vector<Train> trains;
};



int main()
{
	Train t1("218396", "13:30", "London");
	Train t2("735432", "12:35", "Manchster");
	Train t3("123546", "9:20", "Paris");

	TrainSystem s1;
	s1.AddTrain(t1);
	s1.AddTrain(t2);
	s1.AddTrain(t3);

	s1.Print();
	s1.RemoveTrain();
	s1.RemoveTrain();
	s1.RemoveTrain();
	s1.Print();
	s1.findByNumber("218396");
	s1.AddTrain(t1);
	s1.findByNumber("218396");
	
}



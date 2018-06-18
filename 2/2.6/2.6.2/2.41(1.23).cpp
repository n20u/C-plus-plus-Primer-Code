#include <iostream>
#include <string>

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data data1;
	double price = 0;
	
	if (std::cin >> data1.bookNo >> data1.units_sold >> price)
	{
		data1.revenue = data1.units_sold * price;
	    
	    Sales_data data2;
	    unsigned totalCnt = data1.units_sold;
	    double totalRevenue = data1.revenue;
	    
	    while(std::cin >> data2.bookNo >> data2.units_sold >> price)
	    {
	    	data2.revenue = data2.units_sold * price;
	    	
			if (data1.bookNo == data2.bookNo)
				{
					totalCnt = totalCnt + data2.units_sold;
					totalRevenue = totalRevenue + data2.revenue;
				}
			else
				{
					std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
					if (totalCnt != 0)
					    std::cout << totalRevenue/totalCnt << std::endl;
					else
					    std::cout << "(no sales)" << std::endl;
					
					data1 = data2;
					totalCnt = data1.units_sold;
					totalRevenue = data1.revenue;
				}
		}
		
		std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0)
		    std::cout << totalRevenue/totalCnt << std::endl;
		else
		    std::cout << "(no sales)" << std::endl;
		
		return 0;
	}
	else
	{
		std::cerr << "No data?!";
		return -1;
	}
}

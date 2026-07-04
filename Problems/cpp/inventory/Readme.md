Create an Inventory class that a warehouse might use to represent their stock of products and raw materials.

Implement class Inventory with following description.

A. Data Members
    1. description_of_product of type string.
    2. balance_stock of type integer.
    3. productcode of type int.

B. Member functions

    1. default constructor - Initial product stock size should be greater than 20, which is the company’s minimum stock level.

    2. parameterized constructor- validate the initial product to ensure it has a stock greater than 20, which is the company’s minimum stock level.

    3. getter functions for all attributes.
    4. setter functions for all attributes.
    
    5. purchase function- It should add a product to the current stock.

    6. sale function – It should reduce stock. Ensure after each sale that the stock level does not drop below 20.

    7. Search function to find details of particular product. Display appropriate
        message if product not found.

    8.Overload << operator to display product details.

C. Create 5 objects of Inventory class on heap and display their details.

D. Test the member function purchase(),sale() and search().

E. Free memory allocated on heap.

Code should be implemented in three files Inventory.h,Inventory.cpp,Main.cpp

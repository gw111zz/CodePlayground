g++ -v -std=c++11 vector_of_move_only_object.cpp -o vector_of_move_only_object
g++ -v -std=c++11 vector_of_copy_only_object.cpp -o vector_of_copy_only_object

echo "Run this:"
echo "time ./vector_of_move_only_object"
echo "And then:"
echo "time ./vector_of_copy_only_object"


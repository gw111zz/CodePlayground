g++ -v -std=c++11 vector_of_move_only_object.cpp -o vector_of_move_only_object
g++ -v -std=c++11 vector_of_copy_only_object.cpp -o vector_of_copy_only_object

echo "Run this:"
echo "time ./vector_of_move_only_object"
echo "And then:"
echo "time ./vector_of_copy_only_object"

# time ./vector_of_move_only_object
# 
# real	5m30.799s
# user	2m40.973s
# sys	1m55.757s
# 
# time ./vector_of_copy_only_object
# 
# real	6m5.041s
# user	3m10.117s
# sys	1m53.882s

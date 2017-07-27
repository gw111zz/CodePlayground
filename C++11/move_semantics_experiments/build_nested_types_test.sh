g++ -v -std=c++11 nested_types_move_construct.cpp -o nested_types_move_construct
g++ -v -std=c++11 nested_types_copy_construct.cpp -o nested_types_copy_construct

echo "Run this:"
echo "time ./nested_types_move_construct"
echo "And then:"
echo "time ./nested_types_copy_construct"

# time ./nested_types_move_construct
# 
# real	2m41.667s
# user	2m41.330s
# sys	0m0.199s 
#
# time ./nested_types_copy_construct
# 
# real	2m23.224s
# user	2m22.950s
# sys	0m0.171s
#

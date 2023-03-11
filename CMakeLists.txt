cmake_minimum_required(VERSION 3.22)
project(acoj)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#洛谷刷题
add_executable(P1908 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1908逆序对/P1908逆序对.cpp")
add_executable(P1908-1 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1908逆序对/P1908逆序对-25分-超时.cpp")
add_executable(P1177 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1177快速排序/P1177快速排序.cpp")
add_executable(P1177-2 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1177快速排序/P1177快速排序-两路快排.cpp")
add_executable(P1177-3 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1177快速排序/P1177快速排序-两路快排-标准写法.cpp")
add_executable(P1177-4 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.2 排序算法/P1177快速排序/P1177快速排序-三路快排.cpp")
add_executable(P1024 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P1024一元三次方程求解/P1024一元三次方程.cpp")
add_executable(P2678 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P2678跳石头/P2678跳石头.cpp")
add_executable(P1902 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P1902刺杀大使/P1902刺杀大使.cpp")
add_executable(P1902-2 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P1902刺杀大使/P1902刺杀大使-最小生成树解法.cpp")
add_executable(P1314 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P1314聪明的质检员/P1314聪明的质检员.cpp")
add_executable(P1083 "luogu/题单/能力全面提升综合题单/Part 2 基础算法/Part 2.3 二分答案/P1083借教室/P1083借教室.cpp")


#排序算法
add_executable(bubble_sort 排序算法/冒泡排序.cpp)
add_executable(radix_sort 排序算法/基数排序LSD.cpp)
add_executable(heap_sort 排序算法/堆排序.cpp)
add_executable(merge_sort 排序算法/归并排序.cpp)
add_executable(quick_sort 排序算法/快速排序.cpp)
add_executable(quick_sort-2 排序算法/快速排序-2.cpp)
add_executable(quick_sort-3 排序算法/快速排序-3.cpp)
add_executable(quick_sort-4 排序算法/快速排序-4.cpp)
add_executable(quick_sort-5 排序算法/快速排序-两路快排-标准写法.cpp)
add_executable(quick_sort-6 排序算法/快速排序-三路快排.cpp)
add_executable(bucket_sort 排序算法/桶排序.cpp)
add_executable(counting_sort 排序算法/计数排序.cpp)


add_executable(acoj main.cpp)




#file (GLOB files ZJ-01/luogu/*.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()
#file (GLOB files ZJ-01/luogu/*.cpp)

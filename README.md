# lib_partageable_linux_2022
We will use linux on GCP

# 1 - Install git on CGP

![1_install git on cloud](https://user-images.githubusercontent.com/29365707/166929512-e95f8a8c-9204-4558-9c4f-9f55b1fec728.png)

# 2 - Vrifie g++ version 

![2_verifier g++ version](https://user-images.githubusercontent.com/29365707/166930072-8c351c31-a598-4553-ab73-4f241917d7ae.png)


# 3 - Compile and execute "lib_partageable_linux_2022" after updating 

![make](https://user-images.githubusercontent.com/29365707/167018461-67357bb4-440e-4f86-af9f-e7dcd544ab00.png)



# 4 - Use Objdump
Objdump command in Linux is used to provide thorough information on object files

## 4.1 objdump -T main.o 
### 4.1.1 - Before
Display the contents of dynamic symbol table using -T option

![4_objdump _t main](https://user-images.githubusercontent.com/29365707/166932631-55b1c8cb-2873-4448-b370-697fc2424719.png)

## 4.1.2 - After

![objdump](https://user-images.githubusercontent.com/29365707/167018953-a46fa94a-23c8-4023-aed7-584146d028ac.png)


## 4.2 objdump -T libComposant1.so
Display the contents of dynamic symbol table using -T option
Dynamic symbols are those which are resolved during run time.

![5_objdump_T_libcomposant1](https://user-images.githubusercontent.com/29365707/166933431-be139df9-07b2-4b6b-9f63-7d7d9d9443a6.png)


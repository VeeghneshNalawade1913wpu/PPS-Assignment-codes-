food_list=["Dosa","Batata vada","Pizza"]
food_T=("Dosa","Batata vada","Pizza")
#Create Dictionary
food_d={
    1:"Dosa",
    2:"Batata vada",
    3:"Pizza"
}
print("Food List")
print(food_list)

print("Food Tuple")
print(food_T)

print("\nFood Dictionary")
print(food_d)
#add section
food_d[4]="Pav Bhaji"
print("\nAfter Adding ")
print(food_d)
#Update Operations
food_d[2]="Pani Puri"
print("\nAfter Updating")
print(food_d)
#Delete Operations
del food_d[3]
print("\nAfter Deleting")
print(food_d)
#Append
food_list.append("sharwarma")
print("\nAfter Appending")
print(food_list)

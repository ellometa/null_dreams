import numpy as np

lows = np.array([10, 12, 9, 10, 9, 11, 5, 6, 12, 10, 16, 15])
highs = np.array([17, 21, 18, 20, 25, 22, 23, 25, 20, 17, 15, 18])

#overall
print(f"Avg lows of entire year month wise: {np.average(lows)}")
print(f"Avg high of entire year month wise: {np.average(highs)}")

# monthly avgs
monthly_avg = np.average((lows, highs), axis=0)
print("Monthly averages: ", monthly_avg)

# highest and lowest monthly temps
print("Max temps monthly: ", np.max((lows, highs), axis=0))
print("Min temps monthly: ", np.min((lows, highs), axis=0))
highest_month = np.argmax(monthly_avg, axis=0)
lowest_month = np.argmin(monthly_avg, axis=0)

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
print(f"Highest average temperature month: {highest_month + 1} which is {months[highest_month]}")
print(f"Lowest average temperature month: {lowest_month + 1} which is {months[lowest_month]}")

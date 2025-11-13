# Weather Data Visualizations
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load dataset
df = pd.read_csv("weather_aus.csv")

# Drop missing values for clean visuals
df = df.dropna(subset=['MaxTemp', 'Rainfall', 'Humidity3pm', 'Pressure3pm'])

# ✅ Line chart of MaxTemp vs Date for one city
city_df = df[df['Location'] == 'Sydney'].copy()   # Change city name as needed
city_df['Date'] = pd.to_datetime(city_df['Date'])
plt.figure(figsize=(10,5))
plt.plot(city_df['Date'], city_df['MaxTemp'])
plt.title('Max Temperature Over Time - Sydney')
plt.xlabel('Date')
plt.ylabel('MaxTemp (°C)')
plt.show()

# ✅ Histogram of Rainfall
plt.figure(figsize=(6,4))
plt.hist(df['Rainfall'], bins=30, edgecolor='black')
plt.title('Rainfall Distribution')
plt.xlabel('Rainfall (mm)')
plt.ylabel('Frequency')
plt.show()

# ✅ Heatmap: temperature, humidity, pressure
corr = df[['MaxTemp', 'MinTemp', 'Humidity3pm', 'Pressure3pm']].corr()
sns.heatmap(corr, annot=True, cmap='coolwarm')
plt.title('Temperature, Humidity, and Pressure Relationship')
plt.show()

import pandas as pd
import numpy as np
from statsmodels.tsa.arima.model import ARIMA
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

# Load historical energy data
energy_data = pd.read_csv('historical_energy_data.csv')

# Data preprocessing
# Handle missing values
energy_data.dropna(inplace=True)

# Remove outliers
q1 = energy_data['energy'].quantile(0.25)
q3 = energy_data['energy'].quantile(0.75)
iqr = q3 - q1
energy_data = energy_data[(energy_data['energy'] > (q1 - 1.5 * iqr)) & (energy_data['energy'] < (q3 + 1.5 * iqr))]

# Feature engineering
# Assuming 'time' column represents the timestamp of energy data
energy_data['time'] = pd.to_datetime(energy_data['time'])
energy_data['hour'] = energy_data['time'].dt.hour
energy_data['day_of_week'] = energy_data['time'].dt.dayofweek

# Split data into training and testing sets
train_data, test_data = train_test_split(energy_data, test_size=0.2, shuffle=False)

# Time-series forecasting using ARIMA
# Define ARIMA model
model = ARIMA(train_data['energy'], order=(5,1,0))  # ARIMA(p,d,q) parameters may vary based on data
# Fit ARIMA model
model_fit = model.fit()
# Forecast future energy demand/generation
forecast = model_fit.forecast(steps=len(test_data))

# Evaluate forecast performance
mse = mean_squared_error(test_data['energy'], forecast)
print(f'Mean Squared Error: {mse}')

# Integration with Energy Management Systems
# Assuming the forecasted energy demand/generation values are integrated into an EMS
# Further actions can be taken based on forecasted values, such as load scheduling, energy procurement, etc.

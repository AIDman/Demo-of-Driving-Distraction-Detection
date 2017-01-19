# Demo-of-Driver-s-Distraction-Detection
A demo program of detecting whether a driver is focused on driving using one-class SVM and two-class SVM
## Data Sender
choose which driver(subject) to detect
choose the type of SVM (one-class SVM or two-class SVM)
train & save model with the driver's EEG data (with the chosen type of SVM)
send the driver's EEG data to Data Analyzer in real-time
## Data Analyzer
receive EEG data of the driver from Data Sender
judge the driver's status using the trained model
display the driver's status and EEG data in real time

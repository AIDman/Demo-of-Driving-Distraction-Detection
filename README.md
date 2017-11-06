# Demo-of-Driving-Distraction-Detection

Psychological distraction is very dangerous in driving. We developed a SDA-based driving distraction approach 
that discovers prominent features from raw spectrum of EEG data using SDA. This program is a demo how the detection
system works.  

The package implements two classifiers to discriminate normal and distraction status at the back-end (i.e., 
when receiving the signal from SDA feature extraction), the first is a one-class SVM, and the second is a two-class SVM.


## Module 1: Data Sender

### functions of the module:

1. Choose which driver(subject) to detect

2. Choose the type of SVM (one-class SVM or two-class SVM)

3. Train & save model with the driver's EEG data (with the chosen type of SVM)

4. Send the driver's EEG data to Data Analyzer in real-time

## Module 2: Data Analyzer

### functions of the module:

1. Receive EEG data of the driver from Data Sender

2. Judge the driver's status using the trained model

3. Display the driver's status and EEG data in real time

## Document

1. You can get access to the details of the program in the document named 'Document for Demo Program.pdf'.
2. More information can be found in the associated paper 'Sparse Discriminative Analysis and Its Application in Distraction Classification'.


## Licence
Apache 2.0

## Contact

Yanqing Wang (wangyanqing@cslt.riit.tsinghua.edu.cn)
Dong Wang (wangdong99@mails.tsinghua.edu.cn)

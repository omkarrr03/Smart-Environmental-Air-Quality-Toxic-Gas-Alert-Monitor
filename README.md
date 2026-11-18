# Smart-Environmental-Air-Quality-Toxic-Gas-Alert-Monitor
📌 Project Overview
The Smart Environmental Air Quality & Toxic Gas Alert Monitor is an embedded cross-domain IoT system designed to continuously monitor indoor/industrial hazardous gases (CO, Ammonia, Benzene, Smoke, and CO2) along with ambient temperature and relative humidity.

When toxic gas concentrations breach safety thresholds, the device initiates visual LED warnings, activates a high-decibel piezo acoustic alert, displays status messages on an I2C LCD, and transmits real-time telemetry over serial.

Key Hardware Peripherals
Microcontroller: ATmega328P (Arduino Uno / Nano)
Gas Sensor: Hanwei Electronics MQ-135 Air Quality Sensor
Climate Sensor: Aosong DHT22 / AM2302 (Digital Relative Humidity & Temperature)
Human-Machine Interface: 16x2 Character LCD with PCF8574 I2C Backpack & Tactile Mute Button
Acoustic & Optical Alerts: 5V Active Piezo Buzzer & Dual Status LEDs (Green/Red)
🛠️ Hardware Wiring Diagram
              +-----------------------------------------+
              |           Arduino Uno (ATmega328P)      |
              +-----------------------------------------+
                    |           |           |      |
    [MQ-135 AOUT] --+ A0        |           |      +-- D2 [Mute Pushbutton]
    [I2C LCD SDA] --+ A4        |           +--------- D4 [DHT22 Single-Wire]
    [I2C LCD SCL] --+ A5        +--------------------- D8 [Active Buzzer]
                                                      D9 [Red Hazard LED]
                                                     D10 [Green Normal LED]
🔬 Quality Assurance (QA) & Collaborative Workflow
As part of Course Outcome CO2 (Implementation of Collaborative Tools), this repository serves as an industry-standard testbed for:

GitHub Issues & Incident Management: Logging, triaging, and categorizing hardware, firmware, and cross-domain bugs.
Root Cause Analysis (RCA): Applying 5-Why Analysis and Ishikawa (Fishbone) Diagrams to trace embedded system failures down to root causes.
Branching & Pull Request (PR) Workflow: Isolating bug fixes into dedicated branches (fix/qa-xxx), reviewing diffs, and linking commits to closed issues.
Project Planning & Tracking: Organizing tasks, milestones, and deliverables using GitHub Projects (Kanban Board) and sprint milestones.
📂 Repository File Structure
d:\PM_PRJ\
├── .github/
│   ├── ISSUE_TEMPLATE/
│   │   ├── bug_report.md             # Standard firmware bug report template
│   │   ├── feature_request.md        # Enhancement template
│   │   └── qa_hardware_issue.md      # Hardware & electrical QA issue template
│   ├── PULL_REQUEST_TEMPLATE.md      # Structured PR verification template
│   └── workflows/
│       └── embedded_ci.yml           # GitHub Actions workflow for static checks
├── docs/
│   ├── HARDWARE_SCHEMATIC_AND_BOM.md # Detailed circuit BOM and electrical ratings
│   ├── QA_TEST_PLAN.md               # QA test matrices, pass/fail criteria & test cases
│   ├── ROOT_CAUSE_ANALYSIS.md        # 5-Why and Fishbone RCA for 4+ identified issues
│   └── PROJECT_TRACKING_KANBAN.md    # Milestones, task backlog & project timeline
├── src/
│   ├── Config.h                      # Pinouts, calibration constants, threshold limits
│   └── Smart_Air_Quality_Monitor.ino # Main Arduino firmware
├── test/
│   └── test_cases.md                 # Verification test execution logs
├── PROJECT_MANAGEMENT_ACTIVITY_REPORT.md # Complete formal report for Moodle upload
├── LICENSE                           # Open source MIT license
└── README.md                         # Project documentation
🚀 Getting Started & Simulation
1. Arduino IDE Setup
Clone this repository:
git clone https://github.com/<your-username>/PM_PRJ.git
Install required Arduino libraries from the Library Manager (Ctrl + Shift + I):
LiquidCrystal_I2C by Frank de Brabander
DHT sensor library by Adafruit
Adafruit Unified Sensor
Open src/Smart_Air_Quality_Monitor.ino in Arduino IDE.
Select Board: Arduino Uno and your designated COM port.
Click Upload (Ctrl + U).
2. Wokwi Online Simulation
The hardware circuit and firmware can also be directly executed without physical hardware in the Wokwi Arduino Simulator:

Microcontroller: Arduino Uno
Parts: MQ-135 module, DHT22 sensor, 16x2 LCD (I2C), Pushbutton, Piezo Buzzer, LEDs.
📋 Identified QA Issues Summary
Issue ID	Severity	Category	Problem Summary	Root Cause Method	Resolution Status
QA-BUG-001	High	Sensor / Firmware	False threshold alarm triggered during sensor preheat phase	5-Why Analysis	✅ Resolved
QA-BUG-002	Critical	Interface / Bus	I2C bus lockup and firmware freeze under inductive noise	Fishbone Diagram	✅ Resolved
QA-BUG-003	Medium	Hardware / HMI	Mechanical contact bounce on alarm mute switch causing erratic toggles	5-Why Analysis	✅ Resolved
QA-BUG-004	High	Architecture	Blocking delay(2000) causes telemetry lag & missed emergency spikes	5-Why Analysis	✅ Resolved
QA-BUG-005	Low	Signal Integrity	DHT22 single-wire communication checksum failures & nan reading	5-Why Analysis	✅ Resolved
For detailed RCA and technical fixes, refer to docs/ROOT_CAUSE_ANALYSIS.md.

📜 Academic Assessment Mapping
Rubric Criteria	Rubric Requirement (Level: Exceptional - 5 Pts)	Implementation in This Repo
1. Analysis of QA Documentation & GitHub Usage	Thoroughly analyzes QA documentation structure; correctly uses GitHub features (Issues, PRs, Wiki, Labels, Milestones, Projects); documents 4+ QA issues.	Complete .github issue templates, PR templates, Kanban tracking, and 5 detailed QA issue logs.
2. Problem Identification & Root Cause Analysis	Identifies 4+ problems in electronics project; performs thorough root cause analysis using 5-Why or Fishbone (Ishikawa); traces issues in GitHub; clear severity assessment.	5 identified problems across hardware, firmware, interface, and timing with complete 5-Why and Fishbone analyses.
3. Solution Implementation & Documentation	Proposes well-documented solutions for each problem; uses GitHub commits/branches effectively; creates testing/verification evidence.	Dedicated feature branches (fix/qa-*), non-blocking FSM implementation, I2C timeout protection, and test verification logs.

Below is a README.md file written in Markdown that describes your Leach.cc code, its purpose, and the methods it uses. You can copy this directly into a file named README.md in your project directory.
markdown
# LEACH Protocol Simulation in OMNeT++ with INET

This project implements the **Low-Energy Adaptive Clustering Hierarchy (LEACH)** protocol, a classic hierarchical routing protocol for wireless sensor networks (WSNs), using OMNeT++ and the INET framework. The code simulates a distributed clustering algorithm where sensor nodes self-organize into clusters, elect cluster heads (CHs) probabilistically, and transmit data to a base station (BS) via CHs to optimize energy consumption.

## Overview

The `Leach.cc` file defines a custom OMNeT++ module (`inet::Leach`) that models the behavior of sensor nodes in a WSN running the LEACH protocol. Key features include:
- **Cluster Head Election**: Nodes elect themselves as CHs based on a probabilistic threshold.
- **Dynamic Clustering**: Non-cluster head (NCH) nodes join CHs based on received signal strength.
- **TDMA Scheduling**: CHs assign time slots to their cluster members for data transmission.
- **Data Transmission**: NCHs send data to CHs, which aggregate and forward it to the BS.
- **Visualization**: Nodes visually update their icons in the simulation GUI to distinguish CHs from NCHs.

This implementation adheres to the **classic LEACH** algorithm, as originally proposed by Heinzelman et al., with a distributed approach and no centralized control from the BS.

## Prerequisites

- **OMNeT++**: Version 5.x or later (tested with 6.0).
- **INET Framework**: Version 4.x (compatible with OMNeT++ version).
- A configured `omnetpp.ini` file with network settings (e.g., number of nodes, visualization).

## What the Code Does

The simulation models a WSN where:
1. Nodes periodically elect CHs using the LEACH threshold formula.
2. NCHs associate with the CH offering the strongest signal (highest `rxPower`).
3. CHs broadcast their status, receive acknowledgments from NCHs, and assign TDMA slots.
4. NCHs send data to CHs in their assigned slots, and CHs forward aggregated data to the BS.
5. The simulation tracks metrics like control/data packet counts and logs events to CSV files.

The code also updates the visual representation of nodes in the OMNeT++ GUI, showing CHs with a distinct icon (e.g., a red star) and NCHs with a default icon (e.g., a sensor).

## Key Methods

Below are the primary methods in `Leach.cc` and their roles:

### Initialization and Lifecycle
- **`initialize(int stage)`**: Sets up the module, including parameters (e.g., `clusterHeadPercentage`), interfaces, and state variables. Registers the protocol with INET.
- **`start()`**: Configures network interfaces and schedules the first round.
- **`stop()`**: Cancels events and clears memory on shutdown.
- **`finish()`**: Logs final statistics (e.g., packet counts) and generates CSV files.

### Cluster Head Election and State Management
- **`handleMessageWhenUp(cMessage *msg)`**: Main event handler. Elects CHs probabilistically each round and processes incoming packets.
- **`generateThresholdValue(int round)`**: Implements the LEACH threshold formula:  
  \( T(n) = \frac{p}{1 - p \cdot (r \mod \frac{1}{p})} \), where \( p \) is `clusterHeadPercentage` and \( r \) is the round number.
- **`setLeachState(LeachState ls)`**: Updates the node’s state (`ch` or `nch`) and refreshes its visual display.

### Packet Handling and Communication
- **`handleSelfMessage(cMessage *msg)`**: Sends CH advertisement packets when a node becomes a CH.
- **`processMessage(cMessage *msg)`**: Processes incoming packets (CH advertisements, ACKs, schedules, data, BS packets) based on their type.
- **`sendAckToCH(Ipv4Address nodeAddr, Ipv4Address CHAddr)`**: Sends an acknowledgment from an NCH to its chosen CH.
- **`sendSchToNCH(Ipv4Address selfAddr)`**: CH broadcasts a TDMA schedule to its cluster members.
- **`sendDataToCH(Ipv4Address nodeAddr, Ipv4Address CHAddr, double TDMAslot)`**: NCH sends data to its CH in the assigned TDMA slot.
- **`sendDataToBS(Ipv4Address CHAddr, std::string fingerprint)`**: CH forwards aggregated data to the BS.

### Clustering and Scheduling
- **`addToNodeMemory(Ipv4Address nodeAddr, Ipv4Address CHAddr, double energy)`**: Tracks CH options for NCHs based on signal strength (`rxPower`).
- **`getIdealCH(Ipv4Address nodeAddr)`**: Selects the CH with the highest signal strength for an NCH.
- **`addToNodeCHMemory(Ipv4Address NCHAddr)`**: CH records its cluster members and assigns TDMA slots.

### Visualization
- **`refreshDisplay()`**: Updates the node’s icon in the GUI:
  - NCH: `device/sensor`
  - CH: `misc/star` (red-colored for emphasis).

### Logging and Analysis
- **`addToEventLog(...)`**: Logs packet events (sent/received) with timestamps, energy levels, and state.
- **`generateEventLogCSV()`**, **`generateNodePosCSV()`**, **`generatePacketLogCSV()`**: Exports simulation data to CSV files for post-analysis.

## LEACH Variant
This implementation follows the **classic LEACH** protocol:
- Distributed CH election using the probabilistic threshold.
- Dynamic clustering based on signal strength.
- Round-based operation with TDMA scheduling.
- No centralized BS control or explicit energy-based CH selection (beyond logging).

## Usage

1. **Compile the Code**:
   - Place `Leach.cc` in your OMNeT++ project’s source directory (e.g., `src/`).
   - Update the NED file to include the `Leach` module (e.g., as a routing protocol in a `WirelessHost`).
   - Build the project using `make`.

2. **Configure `omnetpp.ini`**:
   ```ini
   [General]
   network = YourNetworkName
   *.numNodes = 50                # Number of nodes
   *.routingProtocol = "Leach"    # Use this module
   *.visualizer.*.networkNodeVisualizer.displayNodes = true  # Enable visualization
   **.clusterHeadPercentage = 0.05  # 5% CHs
   **.roundDuration = 10s          # Round length
Run the Simulation:
Launch in the OMNeT++ GUI (Qtenv) to observe CHs (red stars) and NCHs (sensors).
Check generated CSV files (eventLog.csv, nodePos.csv, packetLog.csv) for results.
Output
GUI: Visual representation of the network with CHs and NCHs distinguished by icons.
Console: Packet statistics (e.g., Total data packets sent to CH: X).
CSV Files: Event logs, node positions, and packet fingerprints for analysis.
Future Improvements
Add energy-based CH election (e.g., for LEACH-E).
Implement multi-hop routing to the BS.
Enhance visualization with additional node stats (e.g., energy levels).
License
This project is provided as-is for educational purposes. Modify and distribute as needed under your preferred license.

### Instructions
1. Copy the entire content above.
2. Paste it into a file named `README.md` in your project root directory.
3. Adjust any specifics (e.g., project name, INET/OMNeT++ versions, or `omnetpp.ini` examples) to match your setup.
4. Use a Markdown viewer (e.g., in GitHub or VS Code) to preview the formatted version.

This README provides a clear overview of your code, its functionality, and how to use it, making it accessible to others (or yourself in the future)! Let me know if you’d like to refine it further.
# Autonomous Logistics and Supply Chain Simulation

## System Architecture / Class Diagram

```text
                                    ┌───────────────────────┐
                                    │       SUPPLIER        │
                                    ├───────────────────────┤
                                    │ - supplierId          │
                                    │ - name                │
                                    │ - products            │
                                    ├───────────────────────┤
                                    │ + supplyProduct()     │
                                    │ + updateDetails()     │
                                    └───────────┬───────────┘
                                                │
                                                │ supplies
                                                ▼
                                    ┌───────────────────────┐
                                    │        PRODUCT        │
                                    ├───────────────────────┤
                                    │ - productId           │
                                    │ - name                │
                                    │ - weight              │
                                    │ - price               │
                                    │ - quantity            │
                                    ├───────────────────────┤
                                    │ + getDetails()        │
                                    │ + updateStock()       │
                                    └───────────┬───────────┘
                                                │
                                                │ stored in
                                                ▼
                                    ┌───────────────────────┐
                                    │       WAREHOUSE       │
                                    ├───────────────────────┤
                                    │ - warehouseId         │
                                    │ - location            │
                                    │ - capacity            │
                                    ├───────────────────────┤
                                    │ + receiveProduct()    │
                                    │ + storeProduct()      │
                                    │ + dispatchProduct()   │
                                    └───────────┬───────────┘
                                                │
                                                │ manages
                                                ▼
                                    ┌───────────────────────┐
                                    │       INVENTORY       │
                                    ├───────────────────────┤
                                    │ - products            │
                                    │ - stockLevel          │
                                    │ - reorderLevel        │
                                    ├───────────────────────┤
                                    │ + addStock()          │
                                    │ + removeStock()       │
                                    │ + checkAvailability() │
                                    │ + restock()           │
                                    └───────────┬───────────┘
                                                │
                                                │ fulfills
                                                ▼
                                    ┌───────────────────────┐
                                    │        CUSTOMER       │
                                    ├───────────────────────┤
                                    │ - customerId          │
                                    │ - name                │
                                    │ - address             │
                                    ├───────────────────────┤
                                    │ + placeOrder()        │
                                    │ + trackOrder()        │
                                    │ + viewOrder()         │
                                    └───────────┬───────────┘
                                                │
                                                │ places
                                                ▼
                                    ┌───────────────────────┐
                                    │         ORDER         │
                                    ├───────────────────────┤
                                    │ - orderId             │
                                    │ - customerId          │
                                    │ - products            │
                                    │ - totalWeight         │
                                    │ - status              │
                                    ├───────────────────────┤
                                    │ + createOrder()       │
                                    │ + calculateWeight()   │
                                    │ + updateStatus()      │
                                    └───────────┬───────────┘
                                                │
                                                │ creates
                                                ▼
                                    ┌───────────────────────┐
                                    │       SHIPMENT        │
                                    ├───────────────────────┤
                                    │ - shipmentId          │
                                    │ - orderId             │
                                    │ - weight              │
                                    │ - source              │
                                    │ - destination         │
                                    │ - status              │
                                    ├───────────────────────┤
                                    │ + createShipment()    │
                                    │ + updateStatus()      │
                                    └───────────┬───────────┘
                                                │
                                                ▼
                            ┌─────────────────────────────────┐
                            │      DISTRIBUTION CENTER        │
                            ├─────────────────────────────────┤
                            │ - centerId                      │
                            │ - location                      │
                            │ - shipments                     │
                            ├─────────────────────────────────┤
                            │ + receiveShipment()             │
                            │ + sortShipment()                │
                            │ + dispatchShipment()            │
                            └───────────────┬─────────────────┘
                                            │
                                            ▼
                            ┌─────────────────────────────────┐
                            │   AUTONOMOUS DECISION SYSTEM    │
                            ├─────────────────────────────────┤
                            │ + selectVehicle()               │
                            │ + selectRoute()                 │
                            │ + optimizeDelivery()            │
                            │ + makeDecision()                │
                            └───────────────┬─────────────────┘
                                            │
                              ┌─────────────┴─────────────┐
                              │                           │
                              ▼                           ▼
                    ┌─────────────────┐         ┌─────────────────┐
                    │     VEHICLE     │         │      ROUTE      │
                    ├─────────────────┤         ├─────────────────┤
                    │ - vehicleId     │         │ - routeId       │
                    │ - capacity      │         │ - source        │
                    │ - currentLoad   │         │ - destination   │
                    │ - status        │         │ - distance      │
                    ├─────────────────┤         │ - estimatedTime │
                    │ + load()        │         │ - cost          │
                    │ + unload()      │         ├─────────────────┤
                    │ + deliver()     │         │ + calculate()   │
                    └────────┬────────┘         │ + getDistance() │
                             │                  └─────────────────┘
                    ┌────────┼────────┐
                    │        │        │
                    ▼        ▼        ▼
                ┌───────┐ ┌───────┐ ┌────────┐
                │  Bike │ │  Van  │ │  Truck │
                ├───────┤ ├───────┤ ├────────┤
                │+deliver│ │+deliver│ │+deliver │
                └───────┘ └───────┘ └────────┘
                    │        │        │
                    └────────┼────────┘
                             ▼
                    ┌─────────────────┐
                    │    DELIVERY     │
                    ├─────────────────┤
                    │ - deliveryId    │
                    │ - shipmentId    │
                    │ - vehicleId     │
                    │ - routeId       │
                    │ - status        │
                    │ - deliveryTime  │
                    ├─────────────────┤
                    │ + startDelivery()│
                    │ + updateStatus() │
                    │ + complete()     │
                    └────────┬────────┘
                             │
                             ▼
                    ┌─────────────────────┐
                    │  SHIPMENT TRACKING  │
                    ├─────────────────────┤
                    │ - trackingId       │
                    │ - shipmentId       │
                    │ - currentLocation  │
                    │ - status            │
                    │ - history           │
                    ├─────────────────────┤
                    │ + trackShipment()  │
                    │ + updateLocation() │
                    │ + updateStatus()   │
                    │ + showHistory()    │
                    └─────────────────────┘


                    ┌──────────────────────────┐
                    │    SIMULATION ENGINE     │
                    ├──────────────────────────┤
                    │ - orders                 │
                    │ - vehicles               │
                    │ - warehouses             │
                    │ - simulationTime         │
                    ├──────────────────────────┤
                    │ + startSimulation()      │
                    │ + processOrders()        │
                    │ + simulateDelivery()     │
                    │ + generateReport()       │
                    └──────────────────────────┘
```

---

## Class Relationships

```text
Supplier ───── supplies ───────► Product

Warehouse ─── contains ─────────► Inventory

Inventory ─── manages ──────────► Product

Customer ──── places ───────────► Order

Order ─────── creates ──────────► Shipment

DistributionCenter ─ manages ───► Shipment

Vehicle ◄──── inherits ────────── Bike
Vehicle ◄──── inherits ────────── Van
Vehicle ◄──── inherits ────────── Truck

Shipment ─── assigned to ───────► Vehicle

Shipment ─── uses ──────────────► Route

Shipment ─── processed by ──────► Delivery

Shipment ─── monitored by ──────► ShipmentTracking

AutonomousDecisionSystem ───────► Vehicle

AutonomousDecisionSystem ───────► Route

SimulationEngine ───────────────► Simulation Components
```

---

## Main Logistics Flow

```text
Supplier
   │
   ▼
Warehouse
   │
   ▼
Inventory
   │
   ▼
Customer
   │
   │ places order
   ▼
Order
   │
   ▼
Shipment
   │
   ▼
Distribution Center
   │
   ▼
Autonomous Decision System
   │
   ├──────────────► Vehicle Selection
   │                    │
   │                    ├── Bike
   │                    ├── Van
   │                    └── Truck
   │
   └──────────────► Route Selection
                        │
                        ▼
                      Route
                        │
                        ▼
                     Delivery
                        │
                        ▼
                 Shipment Tracking
                        │
                        ▼
                    Customer
```

---

## OOP Concepts Covered

### 1. Encapsulation

Private attributes inside classes:

```cpp
class Product
{
private:
    int productId;
    string name;
    double price;
};
```

### 2. Inheritance

```text
Vehicle
├── Bike
├── Van
└── Truck
```

### 3. Polymorphism

```cpp
Vehicle *vehicle;

vehicle->deliver();
```

The behavior can differ for `Bike`, `Van`, and `Truck`.

### 4. Abstraction

`Vehicle` can be an abstract base class with virtual functions.

### 5. Composition

Examples:

```text
Warehouse → Inventory
Order → Products
```

### 6. Aggregation

Examples:

```text
Company → Suppliers
Company → Customers
Company → Vehicles
```

### 7. Function Overloading

Different versions of functions such as:

```cpp
createOrder()
createOrder(Product p)
createOrder(Product p, int quantity)
```

### 8. Function Overriding

```cpp
Bike::deliver()
Van::deliver()
Truck::deliver()
```

### 9. Constructors / Destructors

Used to initialize and clean up objects.

### 10. Exception Handling

Examples:

```text
Insufficient Inventory
Vehicle Overloaded
Invalid Order
Invalid Route
Warehouse Full
```

### 11. STL

Potentially:

```cpp
vector<Product>
vector<Order>
vector<Vehicle*>
map<int, Product>
queue<Order>
priority_queue<Order>
```

### 12. File Handling

Store:

```text
Products
Customers
Orders
Inventory
Vehicles
Shipment History
Simulation Results
```

### 13. Simulation

The `SimulationEngine` controls the complete flow:

```text
Generate/Receive Order
        ↓
Check Inventory
        ↓
Create Shipment
        ↓
Select Vehicle
        ↓
Select Route
        ↓
Dispatch
        ↓
Simulate Movement
        ↓
Update Tracking
        ↓
Complete Delivery
        ↓
Generate Report
```

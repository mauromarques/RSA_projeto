import time
import datetime

# Define the data structure for the table rows
table_data = [
    {"number": i, "last_update_time": "", "status": "", "gps_location": "", "last_message_sent": ""}
    for i in range(2, 7)
]

def update_table():
    for row in table_data:
        row["last_update_time"] = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        row["status"] = "OK"  # Dummy status
        row["gps_location"] = f"{52.5200 + row['number']*0.01:.4f}, {13.4050 + row['number']*0.01:.4f}"
        row["last_message_sent"] = f"Message {row['number']}"

def print_table():
    print(f"OBSERVING OBU: 2\n{'No':<5} {'Last Update Time':<20} {'Status':<10} {'GPS Location':<20} {'Last Message Sent'}")
    print("-" * 80)
    for row in table_data:
        print(f"{row['number']:<5} {row['last_update_time']:<20} {row['status']:<10} {row['gps_location']:<20} {row['last_message_sent']}")

def main():
    for _ in range(5):  # Update table 5 times
        update_table()
        print("\033[H\033[J", end="")  # Clear screen
        print_table()
        time.sleep(2)  # Wait for 2 seconds

if __name__ == "__main__":
    main()

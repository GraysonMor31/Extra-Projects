from math import radians, acos, asin, atan2, sin, cos, sqrt
import tkinter as tk
from tkinter import messagebox


def great_circle_distance(lat1, lon1, lat2, lon2):
    radius = 6371.0087714  # Earth radius in km
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    return radius * (acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2)))

def haversine_distance(lat1, lon1, lat2, lon2):
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    a = sin(dlat / 2) ** 2 + cos(lat1) * cos(lat2) * sin(dlon / 2) ** 2
    return 2 * 6371.0087714 * asin(sqrt(a))

def vincenty_distance(lat1, lon1, lat2, lon2):
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    dlon = lon2 - lon1

    numerator = sqrt((cos(lat2) * sin(dlon)) ** 2 + (cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon)) ** 2)
    denominator = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon)

    delta_sigma = atan2(numerator, denominator)
    
    return 6371.0087714 * delta_sigma


def calculate_distance_km():
    calculate_distance(1, "km")

def calculate_distance_miles():
    calculate_distance(0.621371, "miles")

def calculate_distance_nm():
    calculate_distance(0.539957, "nautical miles")

def calculate_distance_ft():
    calculate_distance(3280.84, "feet")

def calculate_distance_m():
    calculate_distance(1000, "meters")

def calculate_distance(conversion_factor, unit):
    try:
        lat1 = float(entry_lat1.get())
        lon1 = float(entry_lon1.get())
        lat2 = float(entry_lat2.get())
        lon2 = float(entry_lon2.get())
    except ValueError:
        messagebox.showerror("Error", "Invalid input. Please enter valid numbers for the coordinates.")
        return

    if not (-90 <= lat1 <= 90) or not (-90 <= lat2 <= 90) or not (-180 <= lon1 <= 180) or not (-180 <= lon2 <= 180):
        messagebox.showerror("Error", "Invalid input. Latitude must be between -90 and 90, and longitude must be between -180 and 180.")
        return

    vincenty_dist = vincenty_distance(lat1, lon1, lat2, lon2) * conversion_factor
    haversine_dist = haversine_distance(lat1, lon1, lat2, lon2) * conversion_factor
    great_circle_dist = great_circle_distance(lat1, lon1, lat2, lon2) * conversion_factor

    messagebox.showinfo("Distances", f"Vincenty distance: {vincenty_dist:.0f} {unit}\nHaversine distance: {haversine_dist:.0f} {unit}\nGreat Circle distance: {great_circle_dist:.0f} {unit}")
    

root = tk.Tk()

label_lat1 = tk.Label(root, text="Latitude 1")
label_lat1.pack()
entry_lat1 = tk.Entry(root)
entry_lat1.pack()

label_lon1 = tk.Label(root, text="Longitude 1")
label_lon1.pack()
entry_lon1 = tk.Entry(root)
entry_lon1.pack()

label_lat2 = tk.Label(root, text="Latitude 2")
label_lat2.pack()
entry_lat2 = tk.Entry(root)
entry_lat2.pack()

label_lon2 = tk.Label(root, text="Longitude 2")
label_lon2.pack()
entry_lon2 = tk.Entry(root)
entry_lon2.pack()

button_km = tk.Button(root, text="Calculate Distance (km)", command=calculate_distance_km)
button_km.pack()

button_miles = tk.Button(root, text="Calculate Distance (miles)", command=calculate_distance_miles)
button_miles.pack()

button_nm = tk.Button(root, text="Calculate Distance (nautical miles)", command=calculate_distance_nm)
button_nm.pack()

button_ft = tk.Button(root, text="Calculate Distance (feet)", command=calculate_distance_ft)
button_ft.pack()

button_m = tk.Button(root, text="Calculate Distance (meters)", command=calculate_distance_m)
button_m.pack()
root.mainloop()


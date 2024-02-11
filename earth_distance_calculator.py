from math import radians, acos, asin, atan2, sin, cos, sqrt
import tkinter as tk
from tkinter import messagebox


def great_circle_distance(lat1, lon1, lat2, lon2):
    radius = 6371  # Earth radius in km
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    return radius * (acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2)))

def haversine_distance(lat1, lon1, lat2, lon2):
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    a = sin(dlat / 2) ** 2 + cos(lat1) * cos(lat2) * sin(dlon / 2) ** 2
    return 2 * 6371 * asin(sqrt(a))

def vincenty_distance(lat1, lon1, lat2, lon2):
    lat1, lon1, lat2, lon2 = map(radians, [lat1, lon1, lat2, lon2])
    dlon = lon2 - lon1

    numerator = sqrt((cos(lat2) * sin(dlon)) ** 2 + (cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon)) ** 2)
    denominator = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon)

    delta_sigma = atan2(numerator, denominator)
    
    return 6371 * delta_sigma


def calculate_distance():
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

    vincenty_dist = vincenty_distance(lat1, lon1, lat2, lon2)
    haversine_dist = haversine_distance(lat1, lon1, lat2, lon2)
    great_circle_dist = great_circle_distance(lat1, lon1, lat2, lon2)

    messagebox.showinfo("Distances", f"Vincenty distance: {vincenty_dist:.5f} km\nHaversine distance: {haversine_dist:.5f} km\nGreat Circle distance: {great_circle_dist:.5f} km")
    

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

button = tk.Button(root, text="Calculate Distance", command=calculate_distance)
button.pack()

root.mainloop()


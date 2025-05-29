#ifndef DD_SNS_ANGLE_H_
#define DD_SNS_ANGLE_H_

#define DD_SNS_ANGLE_min 0
#define DD_SNS_ANGLE_max 270

void dd_sns_angle_setup();
void dd_sns_angle_loop();

int dd_sns_angle_get_value();
int dd_sns_angle_get_voltage();
int dd_sns_angle_get_voltage_saturated();
int dd_sns_angle_get_voltage_filtered_median();
int dd_sns_angle_get_voltage_filtered_avg();

#endif // DD_SNS_ANGLE_H_
#ifndef __MODEL_JSON_H__
#define __MODEL_JSON_H__

const char recognition_model_string_json[] = {"{\"NumModels\":1,\"ModelIndexes\":{\"0\":\"FAN_STATE_MONITORING_DEMO_RANK_0\"},\"ModelDescriptions\":[{\"Name\":\"FAN_STATE_MONITORING_DEMO_RANK_0\",\"ClassMaps\":{\"1\":\"off\",\"2\":\"shaking\",\"3\":\"speed_1\",\"4\":\"speed_2\",\"5\":\"speed_3\",\"6\":\"tapping\",\"0\":\"Unknown\"},\"ModelType\":\"PME\",\"FeatureFunctions\":[\"GlobalPeaktoPeakofLowFrequency\",\"LinearRegressionStats\",\"NegativeZeroCrossings\",\"NegativeZeroCrossings\"]}]}"};

int32_t recognition_model_string_json_len = sizeof(recognition_model_string_json);

#endif /* __MODEL_JSON_H__ */
